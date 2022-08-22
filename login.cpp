#include <iostream>
#include <fstream>
#include <limits>
#include <sstream>

// home login or register

void home();

// login

void login();
// regis

void regis();
bool check_username(std::string username);

// main menu

void main_menu();


int main() {
	
	home();
	main_menu();
	
	return 0;
}

void home() {

	
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
		case 1: login(); break;
		
		case 2: regis(); break;
		
		case 3: std::cout << "Exit" << std::endl; exit(1);
	}

}

void login(){
	
	std::string username;
	std::string password;
	std::string username_input;
	std::string password_input;
	std::string line;
	std::cout << ">> Input username : ";
	std::cin >> username_input;
	std::cout << ">> Input password : ";
	std::cin >> password_input;
	
	std::fstream Myfile;
	Myfile.open("data.txt", std::ios::in|std::ios::out);
		
	if (Myfile.is_open())
	{
		while(getline(Myfile, line))                 // read all the lines
		if (line.find(username_input) != std::string::npos) // search each line
		{ 
			std::stringstream ss(line);
			ss >> username >> password;
		}
	}
	
	Myfile.close();

	if (username_input != username) {
		std::cout << ">> Username not found." << std::endl;
		login();	
	} else if (password_input == password) {
		std::cout << ">> Login succes." << std::endl;
	} else {
		std::cout << ">> Wrong password." << std::endl;
		login();
	}
	
}

// regis

void regis() {
	
	bool is_exist = true;
	
	std::fstream FILE;
	std::string password;
	std::string password_compare;
	std::string username;
	std::string line;
	std::cout << ">> Input new username : ";
	std::cin >> username;
	while (is_exist) {
		is_exist = check_username(username);
		if (is_exist) {
			std::cout << ">> Username already exist." << std::endl;
			std::cout << ">> Input new username : ";
			std::cin >> username;
		}
	}
	std::cout << ">> Input new password : ";
	std::cin >> password;
	std::cout << ">> Input your password again : ";
	std::cin >> password_compare;
	

	FILE.open("data.txt", std::ios::app | std::ios::out| std::ios::in);
	

	while (password != password_compare) {
		
		std::cout << ">> Your password did not match !." << std::endl;
		std::cout << ">> Input new password : ";
		std::cin >> password;
		std::cout << ">> Input your password again : ";
		std::cin >> password_compare;
	}
	FILE << std::endl;
	FILE << username << '\t' << password << '\n';	
	FILE.close();
	std::cout << ">> Register succes !." << std::endl;
	home();
	
}

bool check_username(std::string username) {
	
	bool is_exist = false;
	
	std::fstream FILE;
	FILE.open("data.txt", std::ios::app | std::ios::out| std::ios::in);
	std::string line;
	
	if (FILE.is_open())
	{
		while(getline(FILE, line)) 
			// read all the lines
		if (line.find(username) != std::string::npos) // search each line
		{ 
			is_exist = true;
		}
	}
	
	FILE.close();
	
	return is_exist;
}

void main_menu() {
	std::cout << ">> Welcome, you entered the main menu !" << std::endl;
}


