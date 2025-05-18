#include <iostream>
#include <fstream>
#include <string>
//#include <regex>            // Include regex library for email validation
using namespace std;

int glob = 0;                // global variables
int global = 10;
int dd, mm, yy;

    bool isNumeric( string str) {
                for (char c : str) {
                if (!isdigit(c)) {
                 return false;
                 
                              }
                         }
                   return true;
          }
          int getNumericInput() {
               string input;
               while (true) {
               cin >> input;
            if (isNumeric(input)) {
              return stoi(input);             //stoi is used to convert "string to an integer"
            }
		else {
            cout << "Invalid input. Please enter a numeric value: ";
            cin.clear(); // Clear the error flag
          //  cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            }
    }
}

class Admin
{
private:
    string username="owais";
    string password="owais123";
    string tickets;
public:
    Admin()
    {
    }
    Admin( string username, string password)
	    {
		username = username;
		password = password;
		}

    bool login(string inputUsername, string inputPassword)
    {
        if (username == inputUsername && password == inputPassword)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

class Booking
{
protected:    //attributes
	  int pnr, pnri;
      char first_name[20], last_name[20], email[20];
      int gender;
      int age;
      string c_no;
      int price=0;
      string journey_date;
      bool validateEmail(const char *email)
     {
        // Use regular expression for email validation
        //regex emailPattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
       // return regex_match(email, emailPattern);
     }

public:

    void passenger_detail()                   // function declare for passenger details
    {
        cout << "\n\n\n*****Enter passenger details*****";
        cout << "\nFirst Name:";
        cin >> first_name;
        cout << "\nLast Name:";
        cin >> last_name;
        cout << "\nEmail Id:";
        cin >> email;

        while (!validateEmail(email))            // Validate email
        {
            cout << "Invalid email format. Please enter a valid email address: ";
            cin >> email;
        }
    }
    int gender_check()                     // to check gender input as valid
    {
           cout << "\nGender:\nMale-press:1::\nFemale-press:2::";
           cin >> gender;
        if (gender > 2)
        {
            cout << "\n\nWrong input entered.\nPlease Try again\n\n"<< endl;
            return gender_check();
        }
        return 0;
    }
    void more_details()
    {
        do
        {
            cout << "\n*****Enter contact no.*****: "<<endl;
            cin >> c_no;

            // Validate the length of the contact number
            if (c_no.length() >= 10 && c_no.length() <= 12)
            {
                cout << "\nSuccessfully entered\n";
            }
            else
            {
                cout << "Invalid\nEnter again\n";
            }
        } while (c_no.length() < 10 || c_no.length() > 12);

            cout << "Age: ";
            age=getNumericInput();

             cout << "\n\n*****Details Entered:*****\n";
             cout << "Name: " << first_name << " " << last_name << endl;
             cout << "Age: " << age << endl;
             cout << "Email id: " << email << endl;
             cout << "Contact No.: " << c_no << endl;
    }

      int getpnr()                         // function to get pnr for domestic booking
    {
        return pnr;
    }

     int getpnri()                       // function to get pnr for international booking
    {
        return pnri;
    }

    void setPrice(int ticketClass)
    {
        // Set the price based on the selected ticket class
        switch (ticketClass)
        {
        case 1:
            price = 50000;
            break;
        case 2:
            price = 30000;
            break;
        case 3:
            price = 20000;
            break;

            //for international
        case 4:
            price = 85000;
            break;
        case 5:
            price = 50000;
            break;
        case 6:
            price = 30000;
            break;
        default:
            cout << "Invalid ticket class.\n";
            break;
        }
    }

    int getPrice() const
    {
        return price;
    }
 };

class Domestic_Booking : public Booking
{
protected:
	int pnr=0;
    char fromDestination[10], toAirportArrival[10], toAirportDeparture[10];
    int choice, src, dest;
    int ticketClass;

public:
    void d_pnr()
    {
        glob++;
        pnr = glob;
    }
  int journy_Details()                  // function declare for domestic journey
    {
        cout << "\nEnter DateOfJourney ." << "Please enter a valid date." << endl;
        do
        {
        	cout << "\nEnter Day:";
        	dd=getNumericInput();

           if (dd > 31 || dd < 1) {
            cout << "Invalid date. Please enter a valid day (1-31)." << endl;
            }
        } while (dd > 31 || dd < 1);

        do
        {
            cout << "\nEnter month:";
            mm=getNumericInput();

           if (mm > 12 || mm < 1) {
            cout << "Invalid month. Please enter a valid month (1-12)." << endl;
            }
        } while (mm > 12 || mm < 1);

        do
        {
            cout << "\nEnter year:";
            yy=getNumericInput();

           if (yy < 2024 || yy >= 2025) {
            cout << "Invalid year. Please enter a valid year (2024-2025)." << endl;
             }
        } while (yy < 2024 || yy >= 2025);
        cout << "\n You have entered:" << dd << "/" << mm << "/" << yy << endl;

        cout << "\t\1.karachi(1) \t\2.Islamabad(2) \t\3.Lahore(3) \t\4.Peshawar(4)" << endl<< endl;
        cout << "\t*****Travelling from which city:*****" << endl;
        src=getNumericInput();
        cout << "\t*****Travelling to which city:*****" << endl;
        dest=getNumericInput();

        if ((src == 1 && dest == 2) || (src == 2 && dest == 1))
        {
            cout << "\t \t \t*****Flights Found*****" << endl << endl;
            cout << "Airline:\tDeparture:\tArrival:    \t\t  Category:\n";
            cout << "\1.PIA(1)\t08:00\t\t11:05:        \t\t Refundable\n";
            cout << "\2.Blue Air(2)\t14:00\t\t17:05:   \t\t Refundable\n";
            cout << "\3.Go Air(3)\t19:00\t\t22:05:     \t\t Refundable\n";
        }

        else if ((src == 1 && dest == 3) || (src == 3 && dest == 1))
        {
            cout << "\t \t \t*****Flights Found*****" << endl << endl;
            cout << "Airline:\tDeparture:\tArrival:    \t\t Category:\n";
            cout << "\1.PIA(1)\t08:00\t\t11:05:         \t\tRefundable\n";
            cout << "\2.Blue Air(2)\t14:00\t\t17:05:    \t\tRefundable\n";
            cout << "\3.Go Air(3)\t19:00\t\t22:05:      \t\tRefundable\n";
        }

        else if ((src == 1 && dest == 4) || (src == 4 && dest == 1))
        {
            cout << "\t \t \t*****Flights Found*****" << endl << endl;
            cout << "Airline:\tDeparture:\tArrival:       \t\t Category:\n";
            cout << "\1.PIA(1)\t08:00\t\t11:05:            \t\tRefundable\n";
            cout << "\2.Blue Air(2)\t14:00\t\t17:05:       \t\tRefundable\n";
            cout << "\3.Go Air(3)\t19:00\t\t22:05:         \t\tRefundable\n";
        }

        else if ((src == 2 && dest == 3) || (src == 3 && dest == 2))
        {
            cout << "\t \t \t*****Flights Found*****" << endl << endl;
            cout << "Airline:\tDeparture:\tArrival:      \t\t Category:\n";
            cout << "\1.PIA(1)\t08:00\t\t11:05:            \t\tRefundable\n";
            cout << "\2.Blue Air(2)\t14:00\t\t17:05:       \t\tRefundable\n";
            cout << "\3.Go Air(3)\t19:00\t\t22:05:         \t\tRefundable\n";
        }

        else if ((src == 2 && dest == 4) || (src == 4 && dest == 2))
        {
            cout << "\t \t \t*****Flights Found*****" << endl << endl;
            cout << "Airline:\tDeparture:\tArrival:      \t\t Category:\n";
            cout << "\1.PIA(1)\t08:00\t\t11:05:            \t\tRefundable\n";
            cout << "\2.Blue Air(2)\t14:00\t\t17:05:       \t\tRefundable\n";
            cout << "\3.Go Air(3)\t19:00\t\t22:05:         \t\tRefundable\n";
        }
        else if ((src == 3 && dest == 4) || (src == 4 && dest == 3))
        {
            cout << "\t \t \t*****Flights Found*****" << endl << endl;
            cout << "Airline:\tDeparture:\tArrival:      \t\t Category:\n";
            cout << "\1.PIA(1)\t08:00\t\t11:05:            \t\tRefundable\n";
            cout << "\2.Blue Air(2)\t14:00\t\t17:05:       \t\tRefundable\n";
            cout << "\3.Go Air(3)\t19:00\t\t22:05:         \t\tRefundable\n";
        }
        else if (src == dest)
        {
            cout << "\nSource and destination can't be same.\nplease Try again\n\n\n" << endl;
            return journy_Details();
        }
        else
        {
            cout << "\nWrong input entered\nplease Try again\n\n\n" << endl;
            return journy_Details();
        }
        return 0;
    }

        int select_flight()          // function declare for selecting flight
    {
        cout << "\nEnter your choice" << endl;
        choice=getNumericInput();
        switch (choice)
        {
        case 1:
            cout << "\n*****Flight selected:*****" << endl;
            cout << "PIA" << endl;
            strcpy(fromDestination, "PIA");           // copy to string
            cout << "Departure Time : 08:00" << endl;
            cout << "Arrival Time: 11:05" << endl;
            strcpy(toAirportDeparture, "8:00");
            strcpy(toAirportArrival, "11:05");
            break;
        case 2:
            cout << "\n*****Flight selected:*****" << endl;
            cout << "Blue Air" << endl;
            strcpy(fromDestination, "Blue Air");       // copy to string
            cout << "Departure Time : 14:00" << endl;
            cout << "Arrival Time: 17:05" << endl;
            strcpy(toAirportDeparture, "14:00");
            strcpy(toAirportArrival, "17:05");
            break;
        case 3: // condition
            cout << "\n*****Flight selected:*****" << endl;
            cout << "Go Air" << endl;
            strcpy(fromDestination, "Go Air");
            cout << "Departure Time : 19:00" << endl;
            cout << "Arrival Time: 22:05" << endl;
            strcpy(toAirportDeparture, "19:00");
            strcpy(toAirportArrival, "22:05");
            break;
        default: // condition
            cout << "Wrong input entered.\nplease Try again" << endl;
            return select_flight();

        }
        return 0;
    }

     void display()                    // function to display details for domestic booking
    {
        cout << "\n*****Ticket Details:*****\n";
        cout << "PNR:" << pnr << endl;
        cout << "Flight:" << fromDestination << endl;
        cout << "Name:" << first_name << " " << last_name << endl;
        cout << "DOJ:" << dd << "/" << mm << "/" << yy << endl;
        cout << "Departure Time:" << toAirportDeparture << endl;
        cout << "Arrival Time:" << toAirportArrival<<endl;
        cout << "Ticket Price: Rs." << price << endl;
    }
};

class International_Booking : public Booking
{
	protected:
	int pnri=0;
    char fromDestination_i[10], toAirportArrival_i[10], toAirportDeparture_i[10];
    int src_i, dest_i, choice_i;
    int ticketClass;

public:
      void i_pnr()
       {
        global++;                         // increment variable
        pnri = global;
       }
     int journey_Detail_i()               // function declare for journey details
      {
           cout << "\nEnter DateOfJourney ." << "Please enter a valid date." << endl;
        do
        {
        	cout << "\nEnter Day:";
        	dd=getNumericInput();
           if (dd > 31 || dd < 1) {
            cout << "Invalid date. Please enter a valid day (1-31)." << endl;
             }
        } while (dd > 31 || dd < 1);

        do
        {
            cout << "\nEnter month:";
            mm=getNumericInput();

           if (mm > 12 || mm < 1) {
            cout << "Invalid month. Please enter a valid month (1-12)." << endl;
             }
        } while (mm > 12 || mm < 1);

        do
        {
            cout << "\nEnter year:";
            yy=getNumericInput();

            if (yy < 2024 || yy > 2025) {
            cout << "Invalid year. Please enter a valid year (2023-2025)." << endl;
             }
        } while (yy < 2024 || yy > 2025);
          cout << "\n You have entered:" << dd << "/" << mm << "/" << yy << endl;

          cout << "\1.London(1) \2.Dubai(2) \3.China(3) \4.Singapore(4) \5.NewYork(5) " << endl << endl;

          cout << "\t*****Travelling from which country:*****" << endl;
          src_i= getNumericInput();
          cout << "\n*****Travelling to which country:*****"<<endl;
          dest_i= getNumericInput();

          if ((src_i == 1 && dest_i == 2) || (src_i == 2 && dest_i == 1))
        {
            cout << "\t \t \t*****Flights Found*****" << endl << endl;
            cout << "Airline:\tDeparture:\tArrival:     \tCategory:\n";
            cout << "\1.Vistara(1)\t10:00\t\t14:05:     \tRefundable\n";
            cout << "\2.Fly Dubai(2)\t14:00\t\t18:05:   \tRefundable\n";
            cout << "\3.Emirates(3)\t18:00\t\t22:05:    \tRefundable\n";
        }

       else if ((src_i == 1 && dest_i == 3) || (src_i == 3 && dest_i == 1))
        {
            cout << "\t \t \t*****Flights Found*****" << endl << endl;
            cout << "Airline:\tDeparture:\tArrival:     \tCategory:\n";
            cout << "\1.Vistara(1)\t10:00\t\t14:05:     \tRefundable\n";
            cout << "\2.Fly Dubai(2)\t14:00\t\t18:05:   \tRefundable\n";
            cout << "\3.Emirates(3)\t18:00\t\t22:05:    \tRefundable\n";
        }

        else if ((src_i == 1 && dest_i == 4) || (src_i == 4 && dest_i == 1))
        {
            cout << "\t \t \t*****Flights Found*****" << endl << endl;
            cout << "Airline:\tDeparture:\tArrival:     \tCategory:\n";
            cout << "\1.Vistara(1)\t10:00\t\t14:05:     \tRefundable\n";
            cout << "\2.Fly Dubai(2)\t14:00\t\t18:05:   \tRefundable\n";
            cout << "\3.Emirates(3)\t18:00\t\t22:05:    \tRefundable\n";
        }

        else if ((src_i == 1 && dest_i == 5) || (src_i == 5 || dest_i == 1))
        {
            cout << "\t \t \t*****Flights Found*****" << endl << endl;
            cout << "Airline:\tDeparture:\tArrival:     \tCategory:\n";
            cout << "\1.Vistara(1)\t10:00\t\t14:05:     \tRefundable\n";
            cout << "\2.Fly Dubai(2)\t14:00\t\t18:05:   \tRefundable\n";
            cout << "\3.Emirates(3)\t18:00\t\t22:05:    \tRefundable\n";
        }

        else if ((src_i == 2 && dest_i == 3) || (src_i == 3 && dest_i == 2))
        {
            cout << "\t \t \t*****Flights Found*****" << endl << endl;
            cout << "Airline:\tDeparture:\tArrival:     \tCategory:\n";
            cout << "\1.Vistara(1)\t10:00\t\t14:05:     \tRefundable\n";
            cout << "\2.Fly Dubai(2)\t14:00\t\t18:05:   \tRefundable\n";
            cout << "\3.Emirates(3)\t18:00\t\t22:05:    \tRefundable\n";
        }

        else if ((src_i == 2 && dest_i == 4) || (src_i == 4 && dest_i == 2))
        {
            cout << "\t \t \t*****Flights Found*****" << endl << endl;
            cout << "Airline:\tDeparture:\tArrival:     \tCategory:\n";
            cout << "\1.Vistara(1)\t10:00\t\t14:05:     \tRefundable\n";
            cout << "\2.Fly Dubai(2)\t14:00\t\t18:05:   \tRefundable\n";
            cout << "\3.Emirates(3)\t18:00\t\t22:05:    \tRefundable\n";
        }

        else if (src_i == 2 && dest_i == 5 || (src_i == 5 && dest_i == 2))
        {
            cout << "\t \t \t*****Flights Found*****" << endl << endl;
            cout << "Airline:\tDeparture:\tArrival:     \tCategory:\n";
            cout << "\1.Vistara(1)\t10:00\t\t14:05:     \tRefundable\n";
            cout << "\2.Fly Dubai(2)\t14:00\t\t18:05:   \tRefundable\n";
            cout << "\3.Emirates(3)\t18:00\t\t22:05:    \tRefundable\n";
        }
        else if (src_i == dest_i)
        {
            cout << "wrong input entered.\nPlease Try again\n\n\n" << endl;
            return journey_Detail_i();
        }
        else
        {
            cout << "Wrong input entered.\nPlease Try again\n\n\n";
            return journey_Detail_i();
        }

        return 0;
    }

    int select_flight_i()                     // function declare for selecting flight
    {
        cout << "\nEnter your choice" << endl;
        choice_i=getNumericInput();
        switch (choice_i)
        {
        case 1:
            cout << "\n*****Flight selected:*****" << endl;
            cout << "Vistara" << endl;
            strcpy(fromDestination_i, "Vistara");                // copy to string
            cout << "Departure Time: 10:00" << endl;
            cout << "Arrival Time: 14:05" << endl;
            strcpy(toAirportDeparture_i, "10:00");
            strcpy(toAirportArrival_i, "14:05");
            break;
        case 2:
            cout << "\n*****Flight selected:*****" << endl;
            cout << "Fly Dubai" << endl;
            strcpy(fromDestination_i, "Fly Dubai");               // copy to string
            cout << "Departure Time: 14:00" << endl;
            cout << "Arrival Time: 18:05" << endl;
            strcpy(toAirportDeparture_i, "14:00");
            strcpy(toAirportArrival_i, "18:05");
            break;
        case 3:
            cout << "\n*****Flight selected:*****" << endl;
            cout << "Emirates" << endl;
            strcpy(fromDestination_i, "Emirates");                // copy to string
            cout << "Departure Time : 18:00" << endl;
            cout << "Arrival Time: 22:05" << endl;
            strcpy(toAirportDeparture_i, "18:00");
            strcpy(toAirportArrival_i, "22:05");
            break;
        default:
            cout << "Wrong input entered" << endl;
            return select_flight_i();
        }
        return 0;
    }
    void display_i()                 // function to display details for international booking
    {
        cout << "\n*****Ticket Details:*****\n";
        cout << "PNR:" <<  pnri << endl;
        cout << "Flight:" << fromDestination_i << endl;
        cout << "Name:" << first_name << " " << last_name << endl;
        cout << "DOJ:" << dd << "/" << mm << "/" << yy << endl;
        cout << "Departure Time:" << toAirportDeparture_i << endl;
        cout << "Arrival Time:" << toAirportArrival_i << endl                                                 ;
        cout << "Ticket Price: Rs." << price << endl;
    }

};
class payment
{
public:
    void pay_detail()
    {
        int choice1;
        string card;
        string cvv,account_no, user_name;
        int mm, yy;

        cout << "\n\n\n*****How would you like to pay?:*****\n";
        cout << "\n1. Debit Card(1) \n2. Credit Card(2) \n";
        cout << "\n\nEnter your choice: ";
        choice1=getNumericInput();

        switch (choice1)
        {
        case 1:
            do
            {
                cout << "\nEnter card no.(10 to 14 numbers): "<<endl;
                //card=getNumericInput();
                cin >> card;

                // Validate the length of the card number
                if (card.length() >= 10 && card.length() <= 14)
                {
                    cout << "\nSuccessfully entered\n";
                }
                else
                {
                    cout << "Invalid\nEnter again\n";
                }
            } while (card.length() < 10 || card.length() > 14);

               cout << "\nEnter card expiry date: ";
            do
            {
                cout << "\nEnter month:";
                mm=getNumericInput();
                //cin >> mm;
                if (mm > 12 || mm < 1)
                {
                    cout << "\n invalid month:";
                }
            } while (mm > 12 || mm < 1);

            do
        {
            cout << "\nEnter year:";
            yy=getNumericInput();

            if (yy < 2024 || yy >= 2028) {
            cout << "Invalid year. Please enter a valid year." << endl;
                }
        } while (yy < 2024 || yy >= 2028);
            cout << "\n Card Expiary Date:" << mm << "/" << yy;

            do
            {
            	//getNumericInput();
                cout << "\nEnter cvv number:(3 numbers): ";
                cin >> cvv;

                // Validate the length of the password
                if (cvv.length() == 3)
                {
                    cout << "\nSuccessfully entered\n";
                }
                else
                {
                    cout << "Invalid\nEnter again\n";
                }
            } while (cvv.length() < 3 || cvv.length() > 3);
            cout << "\n*****Transaction Successful*****\n";
            break;
        case 2:
            do
            {
                cout << "\nEnter card no.(10 to 14 numbers): "<<endl;
                cin >> card;

                // Validate the length of the card number
                if (card.length() >= 10 && card.length() <= 14)
                {
                    cout << "\nSuccessfully entered\n";
                }
                else
                {
                    cout << "Invalid\nEnter again\n";
                }
            } while (card.length() < 10 || card.length() > 14);

            cout << "\nEnter card expiry date: ";
            do
            {
                cout << "\nEnter month:";
                mm=getNumericInput();
                //cin >> mm;
                if (mm > 12 || mm < 1)
                {
                    cout << "\n invalid month:";
                }
            } while (mm > 12 || mm < 1);

            do
            {
                cout << "\nEnter year:";
                yy=getNumericInput();
                //cin >> yy;
                if (yy < 2024 || yy > 2027)
                {
                    cout << "\n invalid year:";
                }
            } while (yy < 2024 || yy > 2027);
            cout << "\n Card Expiary Date:" << mm << "/" << yy;

            do
            {
            	
                cout << "\nEnter cvv number:(3 numbers): ";
                cin >> cvv;

                // Validate the length of the password
                if (cvv.length() == 3)
                {
                    cout << "\nSuccessfully entered\n";
                }
                else
                {
                    cout << "Invalid\nEnter again\n";
                }
            } while (cvv.length() < 3 || cvv.length() > 3);
            cout << "\n*****Transaction Successful*****\n";
            break;

        }
    }
};

void createfile(Domestic_Booking d)                             // file creation for domestic booking
{
    ofstream fin("domestic.txt", ios::binary | ios::app);
    fin.write((char *)&d, sizeof(d));                            // writing to file
    fin.close();
}

void cancelticket(int x)
{
    Domestic_Booking d;
    int f = 0;

    ifstream fout("domestic.txt", ios::binary);      // for reading file
    ofstream fin("domestic1.txt", ios::binary);     // for writing to a new file

    while (fout.read((char *)&d, sizeof(d)))               // reading file
    {
        if (d.getpnr() != x)                              // checking pnr
        {
            d.display();
            cout << "\nYour Above ticket is being canceled:\n" << "Amount refunded:\n";
            f++;                                        // incrementing f if pnr found
        }
        else
        {
            fin.write((char *)&d, sizeof(d));                // writing to file
        }
        fout.read((char *)&d, sizeof(d));
    }

    if (f == 0)                           
        cout << "Ticket not found\n";

    fout.close();
    fin.close();

    remove("domestic.txt");                        // deleting old file
    rename("domestic1.txt", "domestic.txt");       // renaming new file
}

void checkticket(int x) {
    Domestic_Booking d;
    int f = 0;

    ifstream fout("domestic.txt", ios::binary);          

    while (fout.read((char *)&d, sizeof(d))) {            // Reading file
        if (d.getpnr() == x) {
            d.display(); // Display details
            cout << "\nYour ticket found" << endl;
            f++;                                    // Incrementing f if PNR found
            
        }
       // fout.read((char *)&i, sizeof(i));  
    }

    fout.close();

    if (f == 0) {
        cout << "Ticket not found" << endl; // If f==0, PNR not found
    } else {
        cout << "Search completed" << endl; // Indicate that the search is completed
    }
}



void createfilei(International_Booking i)                       // opening a file for international booking
{
    ofstream fin("international.txt", ios::binary | ios::app);
    fin.write((char *)&i, sizeof(i));                    // writing to file
    fin.close();
}
void cancelticketi(int x) {
    International_Booking i;
    int f = 0;

    ifstream fout("international.txt", ios::binary);  // Open the file for reading
    ofstream fin("international1.txt", ios::binary);  // Open the new file for writing

    while (fout.read((char *)&i, sizeof(i)))  // Read from the old file
 {
        if (i.getpnri() != x) {
            i.display_i();  // Display details
            cout << "Your above ticket is being deleted:\n" << "Amount refunded:\n";
            f++;  // Incrementing f if PNR found
        }  
        else
        {
            fin.write((char *)&i, sizeof(i));  // writing to file
        }
        fout.read((char *)&i, sizeof(i));  // Read another record from the old file
    }

    if (f == 0) {
        cout << "\nTicket not found\n";  // If f==0, PNR not found
    }

    fout.close();
    fin.close();

    remove("international.txt");  // Delete the old file
    rename("international1.txt", "international.txt");  // Rename the new file
}

void checkticketi(int x)
{
    International_Booking i;
    int f = 0;
    ifstream fout("international.txt", ios::binary);                // opening file
   while ( fout.read((char *)&i, sizeof(i)))                           // reading file
    {
        if (i.getpnri() != x)                                      // checking pnr
        {
            i.display_i();                                         // display details
            cout << "\nYour ticket" << endl;
            f++;                                                 // incrementing f if pnr found
        }
       // fout.read((char *)&i, sizeof(i));                       // reading another record from the file
    }
    fout.close();
    if (f == 0)                                                 // if f==0, pnr not found
        cout << "Ticket not found" << endl;

}

int main()
{
    Admin a;
    Booking book;
    Domestic_Booking d1;
    International_Booking i1;
    payment p2;
    int ch, ch1, n,total_price;
    char input;
    do
    {
        system("CLS");
        cout<<"#############################################################################################\n";
	    cout<<"                      *                                           *\n";
		cout<<"            *        * *                                         * *        *\n";
		cout<<"           * *        *          WELCOME TO AIRLINE          *        * *\n";
		cout<<"          *   *            *       RERSERVATION       *             *   *\n";
		cout<<"           * *            * *                              * *             * *\n";
		cout<<"            *              *                                *               *\n";
		cout<<"#############################################################################################\n\n";
        cout << "\t   Book your Flight tickets at affordable prices!" << endl;
       	cout<<"#############################################################################################\n";

        cout << "\n\n\t\t\t Book Flight(1) \n\t\t\t Cancel Fight(2) \n\t\t\t Check Ticket(3) \n\t\t\t Admin block(4) \n\t\t\t Exit(5)" << endl;
        cout << "\n\t\t Please enter your choice:"<<endl;
        cout<<"#############################################################################################\n";

        ch=getNumericInput();
        switch (ch)
        {
        case 1:
            system("CLS");
            cout << "\n\n\1.Domestic Fights(1) \n\2.International Flights(2)" << endl;
            cout << "\nPlease enter your option" << endl;
            ch1=getNumericInput();

		   switch (ch1)                           // inner switch case
          {
           case 1:                                 // for booking domestic ticket
    {
            int numPassengers;
            cout << "Enter the number of passengers: ";
            numPassengers=getNumericInput();

        // Loop through each passenger
        for (int i = 0; i < numPassengers; ++i) {
            cout << "\nPassenger " << i + 1 << ":\n";

            d1.d_pnr();
		    d1.journy_Details();
            d1.select_flight();
            d1.passenger_detail();
            d1.gender_check();
            d1.more_details();

            cout << "\n*****Select Class for Domestic flight:*****\n";
            cout << "1. Business Class: Rs.50000\n";
            cout << "2. Economy Class: Rs.30000\n";
            cout << "3. Standard Class: Rs.20000\n";

            int domesticTicketClass;
            cout << "Select Class for Domestic flight (1 for Business Class, 2 for Economy Class, 3 for Standard Class): ";
            domesticTicketClass=getNumericInput();
            d1.setPrice(domesticTicketClass);

             total_price += d1.getPrice();
             p2.pay_detail();
             d1.display();
             createfile(d1);                      // call to create file
        }
             cout << "\nTotal Price for " << numPassengers << " passengers: Rs." << total_price << endl;
    }
            break;
            case 2:
			{                    // for booking international ticket
                   int numPassengers;
                   cout << "Enter the number of passengers: ";
                   numPassengers=getNumericInput();

                   // Loop through each passenger
                for (int i = 0; i < numPassengers; ++i) {
                   cout << "\nPassenger " << i + 1 << ":\n";

                   i1.i_pnr();
                   i1.journey_Detail_i();
                   i1.select_flight_i();
                   i1.passenger_detail();
                   i1.gender_check();
                   i1.more_details();

                cout << "\n*****Select Class for International flight:*****\n";
                cout << "4. Business Class: Rs.85000\n";
                cout << "5. Economy Class: Rs.50000\n";
                cout << "6. Standard Class: Rs.30000\n";

                int internationalTicketClass;
                cout << "Select Class for International flight (4 for Business Class, 5 for Economy Class, 6 for Standard Class): ";
                internationalTicketClass=getNumericInput();
                i1.setPrice(internationalTicketClass);
                  
                total_price = i1.getPrice();
                p2.pay_detail();
                i1.display_i();
                createfilei(i1);                 // call to create file
				}
				
                 cout << "\nTotal Price for " << numPassengers << " passengers: Rs." << total_price << endl;
	       }
             break;
            default:
                cout << "Wrong input entered\nPlease Try again\n\n\n" << endl;
                return main();
            }
            break;
        case 2:
        	{
            // for canceling ticket

            system("CLS");
            cout << " Domestic Fights(1) \n International Flights(2)" << endl;
            cout << "\nPlease enter your option" << endl;
            ch1=getNumericInput();
            if (ch1 == 1)
            {
                cout << "Please enter your PNR no.:" << endl;
                n==getNumericInput();
                cancelticket(n);           // function call for domestic booking cancellation
            }
            else if (ch1 == 2)
            {
                cout << "Please enter your PNR no.:" << endl;
                n==getNumericInput();
                cancelticketi(n);              // function call for international cancellation
            }
            else
            {
                cout << "Wrong input entered\nPlease Try again\n\n\n";
                return main();
            }

            break;
        }
        case 3:
		{                                   // for displaying booked ticket details
            system("CLS");
            cout << " Domestic Fights(1) \n International Flights(2)" << endl;
            cout << "\nPlease enter your option" << endl;
            ch1=getNumericInput();
            if (ch1 == 1)
            { 
                cout << "Please enter your PNR no.:" << endl;
                n==getNumericInput();
                checkticket(n);                   // function call to display domestic ticket details
            }

            else if (ch1 == 2)
            {
                cout << "Please enter your PNR no.:" << endl;
                n==getNumericInput();
                checkticketi(n);              // function call to display international ticket details
            }
            else
            {
                cout << "Wrong input entered.\nPlease Try again\n\n\n";
                return main();
            }
            break;
        }
        case 4:
            system("CLS");
            do
            {
                string inputUsername, inputPassword;
                cout << "Enter username: ";
                cin >> inputUsername;

                cout << "Enter password: ";
                cin >> inputPassword;

                if (a.login(inputUsername, inputPassword) == 1)
                {
                    cout << "Login successful!\n";

                    // Perform admin actions
                    int choice_ad;
                    do
                    {
                        cout << "\n*****Admin Menu:*****\n";
                        cout << "1. Check Tickets\n";
                        cout << "2. Delete Ticket\n";
                        cout << "3. Logout\n";
                        cout << "Enter your choice: ";
                        choice_ad=getNumericInput();
                        //cin >> choice_ad;
                        switch (choice_ad)
                        {
                        case 1:
                               cout << "\nPlease enter your option" << endl;
                        	   cout << " Domestic Fights(1) \n International Flights(2)" << endl;
                               choice_ad=getNumericInput();
                            if(choice_ad == 1){
                               cout << "Please enter your PNR no.:" << endl;
                               n==getNumericInput();
                               //cin >> n;
                               checkticket(n);
                        }
                           else if(choice_ad == 2){
                               cout << "Please enter your PNR no.:" << endl;
                               n==getNumericInput();
                               checkticketi(n);
                        }
                           else {
                               cout << "Wrong input entered\nPlease Try again\n\n\n";
                               return main();
                              }
                            break;

                        case 2:
                        	   cout << "\nPlease enter your option" << endl;
                               cout << " Domestic Fights(1) \n International Flights(2)" << endl;
                               choice_ad=getNumericInput();
                            if(choice_ad == 1){

                               cout << "Please enter your PNR no.:" << endl;
                               n==getNumericInput();
                               cancelticket(n);
                               }
                            else if(choice_ad == 2){

                               cout << "Please enter your PNR no.:" << endl;
                               n==getNumericInput();
                               cancelticketi(n);
                              }
                            else {
                             cout << "Wrong input entered\nPlease Try again\n\n\n";
                             return main();
                              }
                            break;

                        case 3:
                            cout << "Logging out...\n";
                            break;

                        default:
                            cout << "Invalid choice. Try again.\n";
                        }
                    } while (choice_ad != 3);
                }
                else
                {
                    cout << "Login failed. Incorrect username or password.\n";
                    return main();
                }
                    cout << "Press q to exit: ";
                    cin >> ch;
            }   while (ch != 'q');
            
            break;

        case 5:
                system("CLS");
                char choice;
                cout << "Press q to exit: ";
                cin >> choice;
                if (choice == 'q' || choice == 'Q') {
                    return 0;
                }
                break;

            default:
               cout << "Wrong input entered\nPlease Try again.\n\n\n\n" << endl;
        }
               cout << "\n\nPress any key. Back to main Menu:" << endl;
               cin >> input;

          }   while (input == 'Y' || input == 'y');                // condition for do-while loop
              return main();
              return 0;
}
