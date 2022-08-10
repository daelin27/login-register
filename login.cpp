#include <iostream>
#include <fstream>
#include <limits>
#include <map>

// home login or register

void home();

// login

void login(std::map<std::string, std::string> &user_map);
// regis

void regis();
std::string password_regis();

// main menu

void main_menu();

int main() {
	
	home();
	main_menu();
	
	return 0;
}

void home() {
	
	std::map<std::string, std::string> user_map;
	user_map.insert(std::pair<std::string, std::string>("tora","apple"));
	
	int x;
	
	std::cout << ">> Welcome !, select 1 to login, 2 to register, 3 to exit.\n";
	std::cout << ">> ";
	std::cin >> x;
	
	if (!std::cin || x > 3 || x < 1) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << ">> invalid entry." << std::endl;
		home();
	}
	
	switch (x) {
		case 1: login(user_map); break;
		case 2: regis(); break;
		case 3: std::cout << "Exit" << std::endl; exit(0);
	}

}

void login(std::map<std::string, std::string> &user_map){
	
	std::string username_input;
	std::string password_input;
	std::cout << ">> Input username : ";
	std::cin >> username_input;
	std::cout << ">> Input password : ";
	std::cin >> password_input;
	
	for (auto& it : user_map) {
		if (it.first == username_input) {
			if (it.second == password_input) {
				std::cout << ">> Login succes." << std::endl;
				break;
			} else {
				std::cout << ">> Wrong password." << std::endl;
				login(user_map);
			}
		} else {
			std::cout << ">> Username not found." << std::endl;
			login(user_map);
		}
	}
	
}

// regis

void regis() {
	
	std::ofstream myfile ("data.txt", std::ios::out | std::ios::app);
		
	std::map<std::string, std::string> user_map;
	std::string password;
	std::string username;
	std::cout << ">> Input new username : ";
	std::cin >> username;
	password = password_regis();
	user_map.insert(std::pair<std::string, std::string>(username, password));	

	if (myfile.is_open())
	{
		myfile << username << '\t' << password << '\n';
		myfile.close();
	}
	else
		std::cout << "Error opening file" << std::endl;
}

std::string password_regis(){
	
	std::string password;
	std::string password_compare;
	std::cout << ">> Input new password : ";
	std::cin >> password;
	std::cout << ">> Input your password again : ";
	std::cin >> password_compare;
	if (password == password_compare)
	{ 
		std::cout << ">> Register succes !." << std::endl;
		home();
	}
	else {
		std::cout << ">> Your password did not match !." << std::endl;
		password_regis();}
		
	
	return password;	
}

void main_menu(){
	std::cout << ">> Welcome, you entered the main menu !" << std::endl;
}

