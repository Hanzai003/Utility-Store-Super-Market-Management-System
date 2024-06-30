#include <iostream>
#include <fstream>
#include <string>
#include <conio.h> // For _getch() on Windows
#include <unistd.h>
#include <iomanip>
#include <ctime> // Added for time()
#include <sstream> // Include <sstream> for std::stringstream
#include <vector> // Include <vector> for storing filenames
#include <dirent.h> // Include <dirent.h> for directory operations


float net_tot ;




std::string to_string(int value) {
    std::stringstream ss;
    ss << value;
    return ss.str();
}


using namespace std;

string getPassword() {
    string password;
    char ch;
    while (true) {
        ch = _getch();
        if (ch == '\r') { // Enter key
            break;
        }
        if (ch == '\b') { // Backspace key
            if (!password.empty()) {
                cout << "\b \b";
                password.erase(password.size() - 1);
            }
        } else {
            password.push_back(ch);
            cout << '*';
        }
    }
    cout << endl;
    return password;
}

bool validatePhoneNumber(const string& number) {
    // Check length
    if (number.length() != 15) {
        return false;
    }

    // Check format
    for (int i = 1; i < 15; ++i) {
        if (i == 3 || i == 7) {
            if (number[i] != '-') {
                return false;
            }
        } else {
            if (number[i] < '0' || number[i] > '9') {
                return false;
            }
        }
    }

    return true;
}

bool validateNIC(const string& number) {
    // Check length
    if (number.length() != 15) {
        return false;
    }

    // Check format
    for (int i = 0; i < 15; ++i) {
        if (i == 5 || i == 13) {
            if (number[i] != '-') {
                return false;
            }
        } else {
            if (number[i] < '0' || number[i] > '9') {
                return false;
            }
        }
    }

    return true;
}

bool validateEmail(const string& number) {
    // Check length
    if (number.length() < 11) {
        return false;
    }

    string domain = number.substr(number.length()-10);

    if (domain!="@gmail.com") {
        return false;
    }

    if(number.find('@')==0 ) {
        return false;
    }

    return true;
}

void signUpAdmin() {
    system("cls");
    ofstream adminFile("admin.txt", ios::app);
    string name, password, phone, email, nic;
    password = "";
   
    cout << "\t\t\t\t _____________________________________\n";
    cout << "\t\t\t\t|                                     |\n";
    cout << "\t\t\t\t|     Administrator Sign Up           |\n";
    cout << "\t\t\t\t|                                     |\n";
    cout << "\t\t\t\t|_____________________________________|\n";
   
    cout << "Enter your name : ";
    cin >> name;
    
    while(password=="") {
        cout << "Enter your password : ";
        password = getPassword();
    }
    
    do {
        cout << "Enter your phone number in format +xx-xxx-xxxxxxx : ";
        cin >> phone;
    } while (!validatePhoneNumber(phone));
   
    do {
        cout << "Enter your email : ";
        cin >> email;
    } while (!validateEmail(email));
   
    do {
        cout << "Enter your NIC in format xxxxx-xxxxxxx-x : ";
        cin >> nic;
    } while (!validateNIC(nic));
   
    adminFile << name << " " << password << " " << phone << " " << email << " " << nic << endl;
    adminFile.close();
   
    cout << "Administrator signed up successfully!" << endl;
    sleep(2);
}

bool signInAdmin() {
	pk:
    system("cls");
    cout << "\t\t\t\t _____________________________________\n";
    cout << "\t\t\t\t|                                     |\n";
    cout << "\t\t\t\t|     Administrator Sign In           |\n";
    cout << "\t\t\t\t|                                     |\n";
    cout << "\t\t\t\t|_____________________________________|\n";
   
    ifstream adminFile("admin.txt");
    string email, password, storedName, storedPassword, storedPhone, storedEmail, storedNic;
    password = "";
    bool authenticated = false;
   
    cout << "Enter your email: ";
    cin >> email;
    
    while(password == "") {
        cout << "Enter your password: ";
        password = getPassword();
    }
   
    while (adminFile >> storedName >> storedPassword >> storedPhone >> storedEmail >> storedNic) {
        if (storedEmail == email && storedPassword == password) {
            authenticated = true;
            break;
        }
    }
    adminFile.close();
   
    if (authenticated) {
        cout << "Administrator signed in successfully!" << endl;
        sleep(2);
    } else {
        cout << "Invalid email or password!" << endl;
        sleep(2);
        goto pk;
    }
   
    return authenticated;
}

void signUpUser() {
    system("cls");
    ofstream userFile("user.txt", ios::app);
    string name, password, phone, email, nic;
    password = "";
   
    cout << "\t\t\t\t _____________________________________\n";
    cout << "\t\t\t\t|                                     |\n";
    cout << "\t\t\t\t|        User Sign Up                 |\n";
    cout << "\t\t\t\t|                                     |\n";
    cout << "\t\t\t\t|_____________________________________|\n";
   
    cout << "Enter your name: ";
    cin.ignore();
    cin >> name;
    
    while(password=="") {
        cout << "Enter your password: ";
        password = getPassword();
    }
    
    do {
        cout << "Enter your phone number in format +xx-xxx-xxxxxxx : ";
        cin >> phone;
    } while (!validatePhoneNumber(phone));

    do {
        cout << "Enter your email : ";
        cin >> email;
    } while (!validateEmail(email));
   
    do {
        cout << "Enter your NIC in format xxxxx-xxxxxxx-x : ";
        cin >> nic;
    } while (!validateNIC(nic));
   
    userFile << name << " " << password << " " << phone << " " << email << " " << nic << endl;
    userFile.close();
   
    cout << "User signed up successfully!" << endl;
    sleep(2);
}

bool signInUser() {
	pk:
    system("cls");
    
    ifstream userFile("user.txt");
    string email, password, storedName, storedPassword, storedPhone, storedEmail, storedNic;
    password = "";
    bool authenticated = false;
   
    cout << "\t\t\t\t _____________________________________\n";
    cout << "\t\t\t\t|                                     |\n";
    cout << "\t\t\t\t|         User Sign in                |\n";
    cout << "\t\t\t\t|                                     |\n";
    cout << "\t\t\t\t|_____________________________________|\n";
   
    cout << "Enter your email: ";
    cin >> email;
    
    while(password == "") {
        cout << "Enter your password: ";
        password = getPassword();
    }
   
    while (userFile >> storedName >> storedPassword >> storedPhone >> storedEmail >> storedNic) {
        if (storedEmail == email && storedPassword == password) {
            authenticated = true;
            break;
        }
    }
    userFile.close();
   
    if (authenticated) {
        cout << "User signed in successfully!" << endl;
        sleep(2);
    } else {
        cout << "Invalid email or password!" << endl;
        sleep(2);
        goto pk;
    }
   
    return authenticated;
}

class shopping {
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
    void total();
    float discount(float);
    void readAllReceipts(); // New function declaration
    void net_total();
};


void shopping::net_total() 
	
{
    cout << "\n\n\tTotal Net Profit: " << net_tot << endl;
    char i;
    cout<<"\n\n\n Press any Key to go to Main Menu ...";
    cin>>i;
    menu();

}


void shopping::readAllReceipts() {
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(".")) != NULL) {
        vector<string> receiptFiles;
        // Read all files in the directory
        while ((ent = readdir(dir)) != NULL) {
            string filename = ent->d_name;
            if (filename.find("receipt_") != string::npos && filename.find(".txt") != string::npos) {
                receiptFiles.push_back(filename);
            }
        }
        closedir(dir);
        if (receiptFiles.empty()) {
            cout << "No receipts found." << endl;
        } else {
    cout << "\t\t\t\t _____________________________________\n";
    cout << "\t\t\t\t|                                     |\n";
    cout << "\t\t\t\t|       List of receipts              |\n";
    cout << "\t\t\t\t|                                     |\n";
    cout << "\t\t\t\t|_____________________________________|\n";
           // Iterate over each filename in the vector
            for (vector<string>::iterator it = receiptFiles.begin(); it != receiptFiles.end(); ++it) {
                const string& filename = *it;
                cout <<"\n\n\n\t"<< filename << endl;
                // Open the receipt file and print its contents
                ifstream receiptFile(filename.c_str()); // Use c_str() to convert string to const char*
                string line;
                while (getline(receiptFile, line)) {
                    cout << line << endl;
                }
                receiptFile.close();
                
                cout << endl;
            }
            char i;
                cout<<"Presss any key to go to main menu : ";
                cin>>i;
                menu();
        }
    } else {
        perror("Failed to open directory");
    }
}


void shopping::menu() {
    m:
    char choice;
    system("cls");

    
 cout << "\t\t\t\t _____________________________________\n";
    cout << "\t\t\t\t|                                     |\n";
    cout << "\t\t\t\t|     HANZAI Supermarket Main Menu    |\n";
    cout << "\t\t\t\t|                                     |\n";
    cout << "\t\t\t\t|_____________________________________|\n";
    cout << "\t\t\t\t|                                     |\n";
    cout << "\t\t\t\t|  1) Administrator Sign Up           |\n";
    cout << "\t\t\t\t|                                     |\n";
    cout << "\t\t\t\t|  2) Administrator Sign in           |\n";
    cout << "\t\t\t\t|                                     |\n";
    cout << "\t\t\t\t|  3) User Sign Up                    |\n";
    cout << "\t\t\t\t|                                     |\n";
    cout << "\t\t\t\t|  4) User Sign in                    |\n";
    cout << "\t\t\t\t|                                     |\n";
    cout << "\t\t\t\t|  0) Exit                            |\n";
    cout << "\t\t\t\t|                                     |\n";
    cout << "\t\t\t\t|_____________________________________|\n";
    cout << "\n\t\t\t Please select : ";
    cin >> choice;

      switch (choice) {
        case '1':
            signUpAdmin();
            break;
        case '2':
            if (signInAdmin()) {
                administrator();
            }
            break;
        case '3':
            signUpUser();
            break;
        case '4':
            if (signInUser()) {
                buyer();
            }
            break;
        case '0':
            exit(0);
            break;
        default:
            cout << "Invalid choice!" << endl;
            goto m;
    }
}

void shopping::total() {
    system("cls");
    cout << "\n\n\tTotal Net Profit " << net_tot;
}


void shopping::administrator() {
    m:
    char choice;
    system("cls");
    cout << "\t\t\t _____________________________________\n";
    cout << "\t\t\t|                                     |\n";
    cout << "\t\t\t|        Administrator menu           |\n";
    cout << "\t\t\t|                                     |\n";
    cout << "\t\t\t|_____________________________________|\n";
    cout << "\n\t\t\t|                                     |";
    cout << "\n\t\t\t|_____1) Add the product______________|";
    cout << "\n\t\t\t|                                     |";
    cout << "\n\t\t\t|_____2) Modify the product___________|";
    cout << "\n\t\t\t|                                     |";
    cout << "\n\t\t\t|_____3) Delete the product___________|";
    cout << "\n\t\t\t|                                     |";
    cout << "\n\t\t\t|_____4) Display Receipts_____________|";
    cout << "\n\t\t\t|                                     |";
    cout << "\n\t\t\t|_____5) Display Net Profit___________|";
    cout << "\n\t\t\t|                                     |";
    cout << "\n\t\t\t|_____0) Back to main menu____________|";
    cout << "\n\t\t\t|                                     |";
    cout << "\n\t\t\t|_____________________________________|\n";
   
    cout << "\n\n\t Please enter your choice : ";
    cin >> choice;
    
    switch (choice) {
    case '1':
        add();
        break;
    case '2':
        edit();
        break;
    case '3':
        rem();
        break;
    case '4':
        readAllReceipts();
        break;
    case '5':
        net_total();
        break;
        
    case '0':
        menu();
        break;
    default:
        cout << "\a Invalid choice... Please try again...";
        sleep(2);
        goto m;
    }
}

void shopping::buyer() {
    m:
    char choice;
    system("cls");
    cout << "\t\t\t _____________________________________\n";
    cout << "\t\t\t|                                     |\n";
    cout << "\t\t\t|        User menu                    |\n";
    cout << "\t\t\t|                                     |\n";
    cout << "\t\t\t|_____________________________________|";
    cout << "\n\t\t\t|                                     |";
    cout << "\n\t\t\t|_____1) Buy product__________________|";
    cout << "\n\t\t\t|                                     |";
    cout << "\n\t\t\t|_____2) Go Back______________________|";
    cout << "\n\t\t\t|                                     |";
    cout << "\n\t\t\t|_____________________________________|\n\n";
    cout << "\t\t\t Enter your choice : ";

    cin >> choice;
    
    switch (choice) {
    case '1':
        receipt();
        break;
    case '2':
        menu();
        break;
    default:
        cout << "\a Invalid choice... Please try again...";
        sleep(2);
        goto m;
    }
}

void shopping::add() {
    m:
    fstream data;
    int c;
    float p, d;
    string n;
    system("cls");

    cout << "\n\n\t\t\t Add new product";
    cout << "\n\n\t Product code of the product : ";
    cin >> pcode;
    cout << "\n\n\t Name of the product : ";
    cin >> pname;
    cout << "\n\n\t Price of the product : ";
    cin >> price;

    data.open("database.txt", ios::in);

    if (!data) {
        data.open("database.txt", ios::app | ios::out);
        data << pcode << " " << pname << " " << price << "\n";
        data.close();
    } else {
        data >> c >> n >> p;

        while (!data.eof()) {
            if (c == pcode) {
                cout << "\n\n Product code already exists. Please try again!";
                goto m;
            }
            data >> c >> n >> p;
        }
        data.close();

        data.open("database.txt", ios::app | ios::out);
        data << pcode << " " << pname << " " << price << "\n";
        data.close();
    }

    cout << "\n\n\t Record inserted !";
}

void shopping::edit() {
    fstream data, data1;
    int pkey;
    int c;
    float p, d;
    string n;
    system("cls");

    cout << "\n\t\t\t Modify the record";
    cout << "\n\t\t\t Product code : ";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\n\n File doesn't exist!";
    } else {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price;

        while (!data.eof()) {
            if (pkey == pcode) {
                cout << "\n\t\t Product new code : ";
                cin >> c;
                cout << "\n\t\t Name of the product : ";
                cin >> n;
                cout << "\n\t\t Price : ";
                cin >> p;
                data1 << c << " " << n << " " << p << "\n";
                cout << "\n\n\t\t Record edited ";
            } else {
                data1 << pcode << " " << pname << " " << price << "\n";
            }
            data >> pcode >> pname >> price;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");
    }
}

void shopping::rem() {
    fstream data, data1;
    int pkey;
    int c;
    float p;
    string n;
    system("cls");

    cout << "\n\n\t Delete product";
    cout << "\n\n\t Product code : ";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\n\n File doesn't exist!";
    } else {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price;

        while (!data.eof()) {
            if (pcode == pkey) {
                cout << "\n\n\t Product deleted successfully";
            } else {
                data1 << pcode << " " << pname << " " << price << "\n";
            }
            data >> pcode >> pname >> price;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");
    }
}

void shopping::list() {
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\n|_____________________________________________________\n";
    cout << "ProNo\t\tName\t\tPrice\n";
    cout << "\n\n|_____________________________________________________\n";

    while (data >> pcode >> pname >> price) {
        cout << "|   " << left << setw(7) << pcode << setw(45) << pname << setw(10) << price << "|\n";
    }

    data.close();
}




void shopping::receipt() {
    system("cls");
    fstream data;
    int arrc[100], arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float total = 0;
    cout << "\n\n\t\t\t Receipt ";
    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\n\n Empty database...";
    } else {
        data.close();
        list();
        cout << "\n\n\n\t\t\t____________________________\n";
        cout << "\n\t\t\t|                            |";
        cout << "\n\t\t\t|    Please place the order  |";
        cout << "\n\t\t\t|____________________________|\n";
        do {
            m:
            cout << "\n\n Product Code : ";
            cin >> arrc[c];
            cout << "\n Product Quantity : ";
            cin >> arrq[c];
            for (int i = 0; i < c; i++) {
                if (arrc[c] == arrc[i]) {
                    cout << "\n\n Duplicate Product Code. Please try again...";
                    goto m;
                }
            }
            c++;
            cout << "\n\n Want to buy another product? Press y for yes and n for no : ";
            cin >> choice;
        } while (choice == 'y');
        system("cls");

        cout<< "\n\n______________________________________________________________________________________________________________________________\n";
        cout << "|                                                                                                                             |\n";
        cout << "|  ProCode.     Product Name                              Quantity      Price           Amount          GST      Discount     |\n";
        cout << "|                                                                                                                             |\n";
        
        float gst;
        
        for (int i = 0; i < c; i++) {
            fstream data;
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price;
            while (!data.eof()) {
                if (pcode == arrc[i]) {
                    dis = discount(price);
					gst=dis;
					amount = ( price*arrq[i] ) + ( dis*arrq[i] );
					dis = amount - ( dis*arrq[i] ) ;
 					total =total+ dis;

                    cout << "|   " << left << setw(10) << pcode << setw(45) << pname << setw(13) << arrq[i] << setw(16) << price << setw(16) << amount << setw(9) << gst << setw(10) << dis << "   |\n";
                }
                data >>  pcode >> pname >> price ;
            }
        }
        cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t Total Amount : " << total;
        net_tot += total;

        // Save the net profit to a file
        ofstream netProfitFile("net_profit.txt");
        if (netProfitFile.is_open()) {
            netProfitFile << net_tot;
            netProfitFile.close();
        } else {
            cout << "Unable to open file to save net profit." << endl;
        }	
        
        // Generate a unique filename for the receipt
        string filename = "receipt_" + ::to_string(time(0)) + ".txt";

        ofstream receiptFile(filename.c_str()); // Use c_str() to convert string to const char*

        receiptFile << "\n\n______________________________________________________________________________________________________________________________\n";
        receiptFile << "|                                                                                                                             |\n";
        receiptFile << "|  ProCode.     Product Name                              Quantity      Price           Amount          GST      Discount     |\n";
        receiptFile << "|                                                                                                                             |\n";
        for (int i = 0; i < c; i++) {
            fstream data;
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price;
            while (!data.eof()) {
                if (pcode == arrc[i]) {
                    dis = discount(price);
					gst=dis;
					amount = ( price*arrq[i] ) + ( dis*arrq[i] );
					dis = amount - ( dis*arrq[i] ) ;
					total =total+ dis;
                    receiptFile << "|   " << left << setw(10) << pcode << setw(45) << pname << setw(13) << arrq[i] << setw(16) << price << setw(16) << amount << setw(9) << gst << setw(10) << dis << "|\n";
                }
                   data >>  pcode >> pname >> price ;
            }
        }
        receiptFile << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t Total Amount : " << total;
        receiptFile.close();

        cout << "\n\n Your receipt has been saved to " << filename << "\n\n";
    }
    
    
    s:
    cout << "\n\n\t\t\t _____________________________________\n";
    cout << "\n\t\t\t|                                     |";
    cout << "\n\t\t\t|_____1) Repeat_______________________|";
    cout << "\n\t\t\t|                                     |";
    cout << "\n\t\t\t|_____2) Main Menu____________________|";
    cout << "\n\t\t\t|                                     |";
    cout << "\n\t\t\t|_____0) Exit_________________________|";
    cout << "\n\t\t\t|                                     |";
    cout << "\n\t\t\t|_____________________________________|\n\n";
    char cho;
    cout << "Enter you choice : ";
    cin >> cho;

    switch (cho) {
        case '1':
            receipt();
            break;

        case '2':
            menu();
            break;

        case '0':
            exit(0);
            break;

        default:
            cout << "\nInvalid input...";
            goto s;
    }
    
}
 
 
 
                

  float shopping::discount(float pri) {
   
    float gst;

    if (pri >= 0 && pri <= 300) {
        gst = (5 * pri) / 100;
        return gst;
    } else if (pri > 300 && pri <= 500) {
        gst = (8 * pri) / 100;
        return gst;
    } else if (pri > 500 && pri <= 1000) {
        gst = (10 * pri) / 100;
        return gst;
    } else if (pri > 1000 && pri <= 3000) {
        gst = (12 * pri) / 100;
        return gst;
    } else if (pri > 3000) {
        gst = (15 * pri) / 100;
        return gst;
    } else {
        return 0;
    }
}

int main()
{
    system("color F5");


	   ifstream netProfitFile("net_profit.txt");
    if (netProfitFile.is_open()) {
        netProfitFile >> net_tot;
        netProfitFile.close();
    } else {
        cout << "Unable to open file to load net profit." << endl;
    }
    
    
    shopping s;
    s.menu();

    cout << "\n\n\n";
    system("pause");
    return 0;
}
