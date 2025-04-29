#include <iostream>
#include <string>
#include <fstream>  
#include <conio.h>
#include <cctype>
#include <limits> 
#include <regex>// For getch()
using namespace std;
int choice;
string selectUser;
bool logi=false;
bool enduse=false;
string check;
bool valid = false;
bool isValidString(const std::string& str) {
    for (char c : str) {
        if (!std::isalpha(c)) { // Check if each character is alphabetic
            return false;
        }
    }
    return true;
}
class Node{
	 private:
 		string date,accountn,Name,bname;
  		bool paymentMade;
 		string name;
		int quantity;
		string address;
		string street;
		string discription;
		int price;
 		Node*Next;
 		Node*pre;
	public:
		void setname( string n  ){
			name=n;
		}
		string getname(){
			return name;	 
		}
		void setdiscription(string d){
			discription=d;
		}
		string getdiscription(){
			return discription;
		}
		void setaddress( string b  ){
			 address=b;
		}
		string getaddress(){
			return address;	 
		}
		void setstreet( string s  ){
			 street=s;
		}
		string getstreet(){
			return street;	 
		}
		void setdate(string d){
			date=d;
		}
		string getdate(){
			return date;
		}
		void setquantity(int o){
			quantity=o;
		}
		int getquantity(){
			return quantity;
		}
		void setprice(int p){
			price=p;
		}
		int getprice(){
			return price;
		}
		void setName( string x  ){
			Name=x;
		}
		string getName(){
			return Name;	 
		}
		void setbname( string y  ){
			bname=y;
		}
		string getbname(){
			return bname;	 
		}
		void setaccountn( string z  ){
			accountn=z;
		}
		string getaccountn(){
			return accountn;	 
		}
		void setnext(Node*n){
			Next=n;
		}
		Node* getnext(){
			return Next;
		}
		void setpre(Node*o){
			pre=o;
		}
		Node* getpre(){
			return pre;
		}	
		void setPaymentMade(bool status) {
		        paymentMade = status;
		    }
		
		    bool isPaymentMade() {
		        return paymentMade;
		    }
		    
		    // Constructor to initialize paymentMade
		    Node() : paymentMade(false) {}
};
class doubly{
	private:
		Node*head;
		Node*current;
		Node *tail; 
		int size; 
	public:
		doubly(){
			head=NULL;
			current=NULL;
			tail=NULL;
		 	size=0;
		}
		void add(string name,string address,string street,string discription,string date,int quantity ,int price ,string accountn,string Name,string bname){
		    Node*temp;
		    temp=new Node;
		    temp->setname(name);
		    temp->setaddress(address);
		     temp->setstreet(street);
		    temp->setdiscription(discription);
		    temp->setdate(date);
		    temp->setquantity(quantity);
		     temp->setprice(price);
		     temp->setaccountn(accountn);
		     temp->setName(Name);
		     temp->setbname(bname); 
		    temp->setnext(NULL);
		    temp->setpre(NULL); 
		    
		if(size==0)
		{
			head=temp;
			current=temp;
			tail=temp;
			size++;
		}
		else
		{
			temp->setnext(current->getnext());
			temp->setpre(current);
			current->setnext(temp);
		if(temp->getnext()!= NULL)
		{
			(temp->getnext())->setpre(temp);
		}
		else
		{
			tail=temp;
		}
			current=temp;
			size++;
		}
		Node*point=head;
		ofstream file("post.txt");
	file<<"your post is--------------------------"<<endl;
	file<<"name                   == "<<point->getname()<<endl;
	file<<"address                == "<<point->getaddress()<<endl;
	file<<"street no              == "<< point->getstreet()<<endl;
	file<<"discription            == "<<point->getdiscription()<<endl;
	cout<<"post on this date      == "<<point->getdate()<<endl;
	file<<"quantity               == "<< point->getquantity()<<endl;
	file<<"price                  =="<< point->getprice()<<endl;
	file<<"Account number         =="<<point->getaccountn()<<endl;
	file<<"Name                   =="<< point->getName()<<endl;
	file<<"Bank Name              =="<<point->getbname()<<endl;
	file<<"====================================="<<endl;
	file <<"Total payment         : " << point->getprice()*point->getquantity()<<endl;
file.close();
		}
 
void print()
{
	Node*point;
	point=head;
	cout<<endl<<endl<<"POST IS "<<endl;
while(point!=NULL)
{	 
    cout<<"your post is--------------------------"<<endl;
	cout<<"name                   == "<<point->getname()<<endl;
	cout<<"address                == "<<point->getaddress()<<endl;
	cout<<"street no              == "<< point->getstreet()<<endl;
	cout<<"discription            == "<<point->getdiscription()<<endl;
	cout<<"post on this date      == "<<point->getdate()<<endl;
	cout<<"quantity               == "<< point->getquantity()<<endl;
	cout<<"price                  =="<< point->getprice()<<endl;
	cout<<"Account number         =="<<point->getaccountn()<<endl;
	cout<<"Name                   =="<< point->getName()<<endl;
	cout<<"Bank Name              =="<<point->getbname()<<endl;
	cout<<"====================================="<<endl;
	cout <<"Total payment         : " << point->getprice()*point->getquantity()<<endl;
	cout<<endl<<endl;
	point=point->getnext();	 
}
	cout<<endl<<endl<<endl;
}
 
void searchaddress(string  address1)
	    {
	        Node *temp = head;
	        bool found = false;
	        while (temp != NULL)
	        {
	            if (temp->getaddress() == address1)
	            {
	            	cout<<endl<<endl<<endl;
	                cout<<"             Address Found!" << endl;
	                cout<<"Name                : " << temp->getname() << endl;
	                cout<<"Address             : " << temp->getaddress() << endl;
	                cout<<"street              : " << temp->getstreet() << endl;
	                cout<<"unit Price          : " << temp->getprice() << endl;
	                cout<<"date                : "<<temp->getdate()<<endl;
	                cout<<"unit quantity       : "<<temp->getquantity() << endl;
	                cout<<"Discription         : "<<temp->getdiscription() << endl;
	                cout<<" Account number     : "<<temp->getaccountn()<<endl;
	                cout<<"Name of person      : "<<temp->getName()<<endl;
	                cout<<"bank name           : "<<temp->getbname()<<endl;
	                cout << "Total payment     : " << temp->getprice()*temp->getquantity()<<endl;
	                found = true;
	                break;
	            }
	            temp = temp->getnext();
	        }
	        if (!found)
	        {
	            cout << "Address not found." << endl;
	        }
	        cout<<endl<<endl<<endl;
	    }
 
void searchandselete(string name)
{
	Node*oo;
	oo =head;	 
while(oo!=NULL)
{		
	if(oo->getname()==name)
	{
	    if(oo->getname()== head->getname())
		{
		 	cout<<"post is found !!! "<<oo->getname() <<"THIS POST IS DELETED"<<endl;
		 	head=head->getnext();
		 	delete oo;
		 	break;
}
else if(oo->getname()== tail->getname())
{
	cout<<" post is found !!! "<<oo->getname()<<endl;
	tail=tail->getpre();
	delete oo;
	break;	
}
else
{
	cout<<" post is found !!! "<<oo->getname()<<endl;
	(oo->getnext())->setpre(oo->getpre());
	(oo->getpre())->setnext(oo->getnext());
}	
}
	oo=oo->getnext();	
}
}

void profileowner()
{
	cout<<endl<<endl<<endl;
    cout<<"   Owner Profile "<<endl;
    cout<<" Name :  Muhammad Sajjad "<<endl;
    cout<<" use as solar owner "<<endl;
    cout<<endl<<endl<<endl;
}
void profileclient()
{
	cout<<endl<<endl<<endl;
    cout<<"   Client Profile "<<endl;
    cout<<" Name :  Rao Ali Ahmad "<<endl;
    cout<<" use as solar Client "<<endl;
    cout<<endl<<endl<<endl;
}
void menu() {
    string name;
    int quantity;
    string discription;
    string street;
    string address;
    int price;
    string date;
    string accountn;
    string Name, bname;
   string email,password;
     while(true){// Changed to a while loop for continuous menu
        while(logi==false){ // loop to get and validate all info 
					selectUser="";
					do{ // loop to validate owner or client
						cout<<endl<<endl<<endl<<"************  GREEN SHARE  ************"<<endl<<endl;
						cout<<"How you like to login"<<endl;
						cout<<"1. OWNER LOGIN"<<endl;
						cout<<"2. CLIENT LOGIN"<<endl<<endl;
						getline(cin, check);
    					try {
					        choice=stoi(check); // Convert string to integer
					        check="";
					    } catch (const invalid_argument& e) {
					        cout << "Invalid input. Please enter a valid integer." << endl;
					        choice=0;
					    }
						if(choice==1){
							selectUser="owner";
							
						}
						else if(choice==2){
							selectUser="client";
						}
						else{
							system("CLS");
							cout<<"           !!!Wrong Input !!!!"<<endl;
							cout<<"Please re-enter choice..."<<endl;
							}
					}while(selectUser=="");
					
					cout<<endl<<endl<<"$  Enter login info  $   '"<<selectUser<<"'"<<endl;
					char ch;
					email="";
					cout << endl << endl << "  E-mail :";
	           		getline(cin, email);
               		while(email.empty()){
	                	cout << endl << endl << "  E-mail :";
	                	getline(cin, email);
	            	};
                	password="";
					cout<<endl<<"  Password  :";
					while (true) {
				        ch = _getch(); 
				        if (ch == 13) { 
				            cout << endl;
				            break;
				        } else if (ch == 8) { 
				            cout << "\b \b"; 
				            password.pop_back(); 
				        } else {
				            cout << "*"; 
				            password += ch;
				        }
		    		}
		    		if(selectUser=="owner"){
		    			if(email=="owner@gmail.com"&& password=="owner"){
							logi=true;
							cout<<"Login successfully"<<endl;
						}
						else{
							cout<<endl<<endl<<"Invalid email or password"<<endl;
							selectUser="";	
						}
					}else if(selectUser=="client"){
		    			if(email=="client@gmail.com"&& password=="client"){
							logi=true;
							cout<<"Login successfully"<<endl;
						}
						else{
							cout<<endl<<endl<<"Invalid email or password"<<endl;
							selectUser="";	
						}
					}
				}

        if(selectUser=="owner") {
        	cout<<endl<<endl<<endl;
        	cout<<"     **************************************  "<<endl;
			cout << "1. ADD POST" << endl;
            cout << "2. VIEW Profile" << endl;
            cout << "3. SEARCH & DELETE POST" << endl;
            cout << "4. VIEW POST" << endl;
			cout<<"5. View Energy Status"<<endl;
            cout<<"6. Logout"<<endl;
            cout<<"*********   ";
			getline(cin, check);
			try {
		        choice = stoi(check); // Convert string to integer
		        check="";
		    } catch (const invalid_argument& e) {
		        cout << "Invalid input. Please enter a valid integer." << endl;
		        choice=0;
		    }
            if (choice == 1) {
                cout << "Enter Post ID         :" ;
                //cin.ignore(); // Clear the input buffer
                getline(cin, name);
                while(name.empty()){
                    	cout<<"Name can not be empty"<<endl;
	               		cout << endl << endl << "  Enter Post Name  :";
	                	getline(cin, name);
	                };
                cout << "Enter address       :" ;
                getline(cin, address);
                while(address.empty()){
                    	cout<<"Address can not be empty"<<endl;
	               		cout << endl << endl << "  Enter address :";
	                	getline(cin, address);
	                };
                cout << "Enter street no     :" ;
                getline(cin, street);
                while(street.empty()){
                    	cout<<"Street can not be empty"<<endl;
	               		cout << endl << endl << "  Enter street no :";
	                	getline(cin, street);
	                };
                cout << "Enter description   :" ;
                cin.ignore(); 
                getline(cin, discription);
                regex dateFormat(R"(\d{4}-\d{2}-\d{2})"); 
                while (true) {
        		cout << "Enter a date (YYYY-MM-DD): ";
        		getline(cin, date);

       			 if (regex_match(date, dateFormat)) {
          			  
           			 break;
        		} else {
            		cout << "Invalid date format! Please try again.\n";
        		}
   			 	}
                do{
                cout << "Enter quantity      :" ;
                getline(cin, check);
    					try {
					        quantity=stoi(check); // Convert string to integer
					        check="";
					    } catch (const invalid_argument& e) {
					        cout << "Invalid input. Please enter a valid integer." << endl;
					        quantity=0;
					    }
					    if(quantity<=0){
					    	cout << "Invalid input. Please enter a valid integer." << endl;
					        quantity=0;
						}
					}while(quantity==0);
				do{
                cout << "Enter price of unit :" ;
                getline(cin, check);
    					try {
					        price=stoi(check); // Convert string to integer
					        check="";
					    } catch (const invalid_argument& e) {
					        cout << "Invalid input. Please enter a valid integer." << endl;
					        price=0;
					    }
					    if(price<=0){
					    	cout << "Invalid input. Please enter a valid integer." << endl;
					        price=0;
						}
					}while(price==0);
                
                cout << "Enter account number:" ;
                cin >> accountn;
                
                while (!valid) {
			        cout << "Enter name	         :" ;
			        cin.ignore();
                    getline(cin, check);
                    while(check.empty()){
                    	cout<<"Name can not be empty"<<endl;
	               		cout << endl << endl << "  Name :";
	                	getline(cin, check);
	                };
			        if (isValidString(check)) {
			            valid = true;
			            cout << "Valid input: " << check << std::endl;
			            Name=check;
			            check="";
			        } else {
			            cout << "Invalid input! Please enter letters only.\n";
			        }
			    }
			    valid = false;
                while (!valid) {
			        cout << "Enter Bank Name     :" ;
			        getline(cin, check);
                    while(check.empty()){
                    	cout<<"Name can not be empty"<<endl;
	               		cout << endl << endl << "  Name :";
	                	getline(cin, check);
	                };
			
			        if (isValidString(check)) {
			            valid = true;
			            cout << "Valid input: " << check << std::endl;
			            bname=check;
			            check="";
			        } else {
			            cout << "Invalid input! Please enter letters only.\n";
			        }
			    }
			    valid = false;

                add(name, address, street, discription, date, quantity, price, accountn, Name, bname);
            } 
            else if(choice==2) {
            	
                profileowner();
            } 
            else if (choice == 3) {
            	cout<<endl<<endl<<endl;
                cout << "Which name do you want to search and delete..." << endl;
                cout << "Enter your name" << endl;
                getline(cin, name);
                    while(name.empty()){
                    	cout<<"Name can not be empty"<<endl;
	               		cout << endl << endl << "  Enter your name :";
	                	getline(cin, name);
	                };
                searchandselete(name);
            }  
            else if (choice == 4) {
            	cout<<endl<<endl<<endl;
                print();
            }
            else if(choice==5){
				const int totalEnergy=15;
				int energyUsed=8;
				int extraEnergy=totalEnergy-energyUsed;	
				cout<<endl<<endl<<endl;
				cout<<endl<<endl<<"*****************************"<<endl<<endl;
				cout<<"Total Energy : "<<totalEnergy<<" KW/h"<<endl;
				cout<<"Energy Used  :  "<<energyUsed<<" KW/h"<<endl;
				cout<<"Extra Energy :  "<<extraEnergy<<" KW/h"<<endl;
			 
		cout<<endl<<endl;
			}
            else if (choice == 6) {
                logi=false;
                selectUser="";
                menu();
            }
            else {
                cout << "Invalid choice" << endl;
            }
        }
        else if (selectUser=="client") {
        	cout<<endl<<endl<<endl;
            cout << "1. Search post by Address" << endl;
            cout << "2. View Energy Status" << endl;
            cout << "3. View post" << endl;
            cout<<  "4. Make payment "<<endl;
			cout<<"5. View Profile"<<endl;
            cout<<"6. Logout"<<endl;
            cout<<"*********  ";
            getline(cin, check);
                try {
                    choice = stoi(check); // Convert string to integer
                    check = "";
                } catch (const invalid_argument& e) {
                    cout << "Invalid input. Please enter a valid integer." << endl;
                    choice = 0;
                }

            if (choice == 1) {
                string address1;
                cout << "Enter address(Location)   :  ";
                getline(cin, address1);
                     while(address1.empty()){
                    	cout<<"Address can not be empty"<<endl;
	               		cout << endl << endl << "  E-address1 :";
	                	getline(cin, address1);
	                };
                    searchaddress(address1);
            }
            else if (choice == 2) {
                 int totalEnergyUsed=55;
				string OwnerName="Muhammad SAJJAD";
				double amountToPay=totalEnergyUsed*15;
				cout<<endl<<endl<<endl;
				cout<<endl<<endl<<"*****************************"<<endl<<endl;
				cout<<"Total Energy Used : "<<totalEnergyUsed<<" Unit"<<endl;
				cout<<"Owner Name        :  "<<OwnerName<<endl;
				cout<<"Amount To Pay     :  "<<amountToPay<<" PKR"<<endl<<endl<<endl;
				cout<<endl<<endl;
            }
            else if (choice == 3) {
                print();  
            }
            else if(choice==4){
            	string nam;
            	cout << "Enter owner name  :  " ;
                getline(cin, nam);
            	 makePayment(nam);
			}
			else if(choice==5){
				profileclient();
			}
			else if (choice == 6) {
                logi=false;
                selectUser="";
                menu();
            }
            else {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
}
}
void makePayment(string nam) {
    Node* temp = head;
    bool found = false;

    while (temp != NULL) {
        if (temp->getName() == nam) {
            found = true;
            double totalPayment = temp->getprice() * temp->getquantity();
            cout << "Total amount to be paid for " << nam << " is: " << totalPayment << endl;

            // Simulate payment processing
            char confirm;
            
			while(true){
            	cout << "Do you want to proceed with the payment? (y/n): ";
            	cin >> confirm;
				if (isalpha(confirm)) {
            		cout << "Valid input: " << confirm << std::endl; // Exit the loop if input is valid
       			} else {
            		cout << "Invalid input! Please enter a single letter.\n";
            		cin.clear();
            		cin.ignore(numeric_limits<streamsize>::max(), '\n');
        		}
            if (confirm == 'y' || confirm == 'Y') {
                temp->setPaymentMade(true);
                cout << "Payment successful for " << nam << "!" << endl;
                cout<<  "Bank Account is        " <<temp->getaccountn()<<endl;
                cout<<  "Bank name is           " <<temp->getbname()<<endl;
                break;
            } else {
                cout << "Payment cancelled." << endl;
            }
            
        
        temp = temp->getnext();
    }
}
}
    if (!found) {
        cout << "Post not found for payment." << endl;
    }
}
 
};
int main()
{

    
    
	//cout<<"  GREEN SHARE "<<endl;
   doubly a;
   a.menu();
    return 0;
}