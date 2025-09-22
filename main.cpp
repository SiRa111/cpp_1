#include <iostream>
#include <string>
#include <vector>
using namespace std;

//defining base class
class Vehicle {
    public:
        string id;
        string brand;
        string model;
        int year;
        int rentalPrice;
        bool availability;
    
    //constructor
    protected:
        Vehicle (string _id, string _brand, string _model, int _year, int _rentalPrice, bool _availability) {
            id=_id;
            brand = _brand;
            model = _model;
            year = _year;
            rentalPrice = _rentalPrice;
            availability= _availability;
        }
    public:
        virtual void displayInfo() {
            cout << "Id: " << id << endl;
            cout << "Brand: " << brand << endl;
            cout << "Model: " << model  << endl;
            cout << "Year: " << year << endl;
            cout << "Rent: " << rentalPrice << endl;
            cout << "Availability: " << availability << endl;
        }
};


//defining derived class 1
class Car : public Vehicle {

    private:
        int seats;
        
    public:

        Car (string _id, string _brand, string _model, int _year, int _rentalPrice, bool _availability, int _seats) 
            :Vehicle (_id, _brand, _model, _year, _rentalPrice, _availability)
            , seats(_seats)
            {   
                 
            }  
            void displayInfo() {
                cout << "Id: " << id << endl;
                cout << "Brand: " << brand << endl;
                cout << "Model: " << model  << endl;
                cout << "Year: " << year << endl;
                cout << "Rent: " << rentalPrice << endl;
                cout << "Availability: " << availability << endl;  
                cout << "Seats: " << seats << endl;      
            }
                  
};

//defining derived class 2
class Bike : public Vehicle {
    private:
        string cc;
    public:
        Bike (string _id, string _brand, string _model, int _year, int _rentalPrice, bool _availability, string _cc) 
            :Vehicle (_id, _brand, _model, _year, _rentalPrice, _availability)
            , cc(_cc)
            {
                
            }    
             
        void displayInfo() {
            cout << "Id: " << id << endl;
            cout << "Brand: " << brand << endl;
            cout << "Model: " << model  << endl;
            cout << "Year: " << year << endl;
            cout << "Rent: " << rentalPrice << endl;
            cout << "Availability: " << availability << endl;  
            cout << "Engine: " << cc << endl;  
        };
    };  
 
int main() {

    Vehicle* ptr;
    vector <Vehicle*> vehicles;

    while (true) {
        int n;
        cout << "Please choose the required option (press the number): " << endl;
        cout << "1. Add a vehicle" << endl;
        cout << "2. Remove a vehicle" << endl;
        cout << "3. Rent a vehicle" << endl;
        cout << "4. Enter if done" << endl;
        cin >> n;

        
        if (n==1) {
            int p;
            cout << "Please choose the required option (press the number): " << endl;
            cout << "1. Add a Car" << endl;
            cout << "2. Add a Bike" << endl;
            cin >> p;

            if (p==1) {
                string id, brand, model, cc;
                int year, rent, seats;
                bool availability;
                cout << "Enter car details: " << endl;

                cout << "Enter Car Id: ";
                cin >> id;
                cin.ignore(); // clear leftover newline

                cout << "Enter Car Brand: ";
                getline(cin, brand); // allows spaces

                cout << "Enter Car Model: ";
                getline(cin, model); // allows spaces

                cout << "Enter Manufacturing Year: ";
                cin >> year;
                cin.ignore();

                cout << "Enter Rent per Day: ";
                cin >> rent;
                cin.ignore();

                cout << "Enter Availability (1=Yes, 0=No): ";
                cin >> availability;
                cin.ignore();

                cout << "Enter Number of Seats: ";
                cin >> seats;
                cin.ignore();
                
                vehicles.push_back(new Car(id, brand, model, year, rent, availability, seats));

            } 

            else if (p==2) {
                string id, brand, model, engine;
                int year, rent;
                bool availability;
                cout << "Enter Bike details: " << endl;

                cout << "Enter Bike Id: ";
                cin >> id;
                cin.ignore(); // clear leftover newline

                cout << "Enter Bike Brand: ";
                getline(cin, brand); // allows spaces

                cout << "Enter Bike Model: ";
                getline(cin, model); // allows spaces

                cout << "Enter Manufacturing Year: ";
                cin >> year;
                cin.ignore();

                cout << "Enter Rent per Day: ";
                cin >> rent;
                cin.ignore();

                cout << "Enter Availability (1=Yes, 0=No): ";
                cin >> availability;
                cin.ignore();

                cout << "Enter Engine details ";
                cin >> engine;
                cin.ignore();
                
                vehicles.push_back(new Bike(id, brand, model, year, rent, availability, engine));

            }
        }

    else if (n==2) {
        string del;
        cout << "Please enter the id of the vehicle: ";
        cin >> del;

        for (auto it = vehicles.begin(); it != vehicles.end(); ++it) {
            if ((*it)->id == del) {     // use -> because *it is a pointer
            (*it)->displayInfo();       // call display through pointer
            delete *it;             // free the heap object
            vehicles.erase(it);     // remove pointer from vector
            break;                  // stop — iterator would be invalid after erase
    }
}

        }

    else if (n==3) {
        string n;
        for (auto it = vehicles.begin(); it != vehicles.end(); ++it) {
            if ((*it)->id == n && (*it)->availability == 1) {
                (*it)->displayInfo(); 
                cout << endl;
            }
        }
            
        cout << "Please enter the id you want to rent: ";
        cin >> n;

        for (auto it = vehicles.begin(); it != vehicles.end(); ++it) {
            if ((*it)->id == n && (*it)->availability == 1) { 
                cout << "The details of your rented vehicle are: ";    
                (*it)->displayInfo(); 
                (*it)->availability = 0;
            }
            else if ((*it)->id == n && (*it)->availability == 0) {
                cout << "The vehicle is not available." << endl;
            }
            else {
                cout << "Please enter the correct id. " << endl;
                break;
            }
        }
    }
    else if (n==4) {
        break;
    }
    else {
        "Please choose a valid number.";
    }
    }
}
    
