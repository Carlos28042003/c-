#include <iostream>
#include <fstream>//for file creation(write files)
#include <sstream>//for file creation(read files)
#include <string>

using namespace std;

int main(){
	int a, i=0;
	string text, old, password1, password2, pass, name, password0, age, user, word, word1;
	string creds[2], cp[2];
	
	cout << "Security System" << endl;
	
	cout << "_____________________________" << endl <<endl;
	cout << "|       1. Register         |" << endl;
	cout << "|       2. Login            |" << endl;
	cout << "|       3. Change Password  |" << endl;
	cout << "|_______4. End Program______|" << endl <<endl;
	
	do{
		cout << endl << endl;
		cout << "Enter your choice: -";
		cin >> a;
		switch(a){
//To create registration			
			case 1: {
				cout << "____________________________________" << endl <<endl;
				cout << "|--------------Register------------|" <<endl;
				cout << "|___________________________________|" <<endl <<endl;
				cout << "Enter your username: -" << endl;
				cin >> name;
				cout << "Please enter the Password: -" << endl;
				cin >> password0; 
				cout << "Please enter your age: -" << endl;
				cin >> age;
				
				ofstream of1;// used to create files
				of1.open("file.txt");
				if(of1.is_open()){//when the file is open will store the user name and password
					of1 << name << "\n";
					of1 << password0 << "\n";
					cout << "Registration sucessfull!" << endl;
				}
			
				break;
			}
//To login in our system			
			case 2:{
				i= 0;//
				
				cout << "______________________________________" << endl << endl;
				cout << "|----------------Login---------------|" << endl;
				cout << "|____________________________________|" << endl;
				
				ifstream of2;
				of2.open("file.txt");
				cout << "Please enter the username: -" << endl;
				cin >> user;
				cout << "Enter the password: -" << endl;
				cin >> pass;
				
				if(of2.is_open()){
					while(!of2.eof()){
						while(getline(of2, text)){
							istringstream iss(text);
							iss >> word;
							creds[i] = word;
							i++;
						}
						
						if(user == creds[0] && pass == creds[1]){
							cout << "-------Login sucessfull-----";
							cout << endl << endl;
							
							cout << "Details: " <<endl;
							
							cout << "Username: " +name << endl;
							cout << "Password: " +pass << endl;
							cout << "Age :" +age << endl;
							
						}
						
						else{
							cout << endl << endl;
							cout << "Incorrect Credentials" << endl;
							cout << "|       1. Press 2 to login     |" << endl;
							cout << "| 1. Press 2 to change password |" << endl;	
							break;
						}
					}
				}
				break;
			}
//Change password			
			case 3:{
				i = 0;
				
				cout << "------------------Change password--------------" << endl;
				ifstream of0;
				of0.open("file.txt");
				cout << "Enter the old Password: -" << endl;
				cin >> old;
				if(of0.is_open()){
					while(of0.eof()){
						while(getline(of0, text)){
							istringstream iss(text);
							iss >> word1;
							cp[1] = word1;
							i++;
						}
						if(old == cp[1]){
							of0.close();
							ofstream of1;
							if(of1.is_open()){
								cout << "Enter your new password: -" << endl;
								cin >> password1;
								cout << "Enter your password again: -" << endl;
								cin >> password2;
								
								if(password1 == password2){
									of1 << cp[0] << "\n";
									of1 << password1;
									cout << "Password change sucessfully" << endl;
								}
								
								else {
									of1 << cp[0] << "\n";
									of1 << old;
									cout << "The password don't match" << endl;
								}
							}
						}
						else{
							cout << "Please enter a valid password" << endl;
							break;
						}
					}
				}
				break;
			}
//End program
			case 4:{
				cout << "________________Thank you!__________________";
				break;
			}
			default :
				cout << "Enter the valud choice!";			
		}
	}while(a!=4);
	return 0;
}
