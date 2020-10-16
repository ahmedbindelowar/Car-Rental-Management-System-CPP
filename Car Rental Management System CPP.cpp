/*EOP Final Project Section 1
 * Luxury Car Rental Management System
 * Tahmid Alam 1827755
 * Ahmed Bin Delowar 1825969
*/



#include <iostream> 							     // A C++ Header file for input-output standard library 
#include <iomanip>							   // To define manipulator function
#include <string>                                // C++ string header, to use the string data type 
#include <conio.h>							// To indicate console input and output
#include <cctype>							   // A character handling function 
#include <fstream>                         // Stream class to both read and write from/to files.

using namespace std;							

struct Client_information{						//A structure to create a group of variables with different data type
												//This struct is to store the client info in the same structure  
   string client_name[20];
   string client_passport_no[20];
   string client_license_no[20];
   double client_contact_no[20];
   string client_address[20];
   double car_hour;
   double total_price;
   };
   Client_information Client_info;				//Client_info is defined in the main function 
 struct Car_information 						
 {
     string car_brand[14]={"Range Rover","BMW","Bently","Rolls Royce","Mercedes","Audi","Lamborghini","Volkswagen","McLaren","Ford","Porsche","Cadillac","Toyota","Lexus"};
    string car_model[14]={"Range Rover SV Autobiography","BMW Alpina XB7","Bentley Continental GT","Rolls-Royce Ghost","Maybach S650 Cabriolet","Audi A8","Lamborghini Urus","VW Tiguan","McLaren P1","Ford F-150 Limited","Porsche Panamera Turbo Executive","Cadillac Escalade","Toyota Century","Lexus LS 500"};
    string car_colour[14]={"Mescalito Black","Blue Metallic","Anthracite Satin","White Sands","Zircon Red","Glacier white Metallic","Grigio Lynx","Deep Black Pearl","Tarocco Orange","Ruby Red","Jet Black Metallic","Red Passion Tintcoat","Kamui Eternal Black","Manganese Luster"};
    string body_style[14]={"Luxury SUV","SUV version of the 7-Series","Coupe","4-door saloon","Cabriolet","Luxury Sedan","5-door SUV","5-door SUV","Coupe","Luxury Pickup","Sports","Full-size Luxury SUV","Luxury Sedan","Sedan"};
    string horsepower[14]={"557","612","626","562","621","335","641","184","903","290","550","420","156 bhp","416"};
    double per_hour_rate[14]={120,100,200,180,160,110,180,80,180,110,150,110,160,130};
    int car_model_year[14]={2019,2019,2020,2018,2017,2020,2018,2019,2019,2019,2020,2019,2020,2019};
};
 Car_information car_info;						//car_info is defined in the main function
 
  void Car_Selection()							//A void function to select a car (no return type)
 {
   int car_selection=1;
   for(int i=0;i<=13;i++)
   {
    cout<<endl;
    cout<<endl;
    cout<<" Please press " <<car_selection<<" if you want to drive a brand new "<<car_info.car_brand[i];
    cout<<endl;
    car_selection++;
 }
}
 void Car_informations(int car_selecting)		//A void function for providing selected car details (no return type)
  {
  	 cout<<endl;
     cout<<endl;
     cout<<endl;
     cout<<" The available vehicle of "<<car_info.car_brand[car_selecting-1]<<" is shown below - ";
     cout<<endl;
     cout<<endl;
     cout<<endl;
     cout<<" Model: "<<car_info.car_model[car_selecting-1];
     cout<<endl;
     cout<<" Color: "<<car_info.car_colour[car_selecting-1];
     cout<<endl;
     cout<<" Vehicle Body Style: "<<car_info.body_style[car_selecting-1];
     cout<<endl;
     cout<<" Horsepower: "<<car_info.horsepower[car_selecting-1];
     cout<<endl;
     cout<<" Price per hour: "<<car_info.per_hour_rate[car_selecting-1]<<"RM";
     cout<<endl;
     cout<<" Model Year: "<<car_info.car_model_year[car_selecting-1];
     cout<<endl;
     cout<<endl;
     cout<<endl;
}

   void Invoice(int client_seleting)			//A void function to calculate the rent (no return type)
  {
      if(Client_info.car_hour>=12)
      {
           Client_info.total_price=Client_info.car_hour*car_info.per_hour_rate[client_seleting];
      cout<<endl;
      cout<<endl;
      cout<<" Thank you Mr/Mrs "<<Client_info.client_name[client_seleting]<<" you have booked "<<car_info.car_model[client_seleting]<<" for "<<Client_info.car_hour<<" hours.";
      cout<<endl;
      cout<<" The total cost of rent is: RM "<<Client_info.total_price;
      cout<<endl;
      }
            
       else
       {
        cout<<endl;
       cout<<endl;
       cout<<" Sorry the minimum hour for car rent is 12";
       cout<<endl;
       cout<<endl;
       }
       
     

  }
int main()							//Main function 
{
    int user_authentication();       
    user_authentication();			//This function has been called here in the main function

      string client_confirmation;
      int car_selecting ;
     cout<<endl;
     cout<<endl;
     cout<<endl;
     cout<<endl;
     cout<<"---------------Luxury Car Rental Management System---------------";
     cout<<endl;
     cout<<endl;
     cout<<endl;
     cout<<" Please select a vehicle brand of your choice - ";
     cout<<endl;
     cout<<endl;
     while(client_confirmation!="e" && client_confirmation!="E")
     {
    Car_Selection();
    cout<<endl;
    cout<<endl;
    cout<<" ------------------------------";
    cout<<endl;
    cout<<" Press any key from 1 to 14 to select a vehicle brand of your choice: ";
    cin>>car_selecting ;
    cout<<" ------------------------------";
    cout<<endl;
    
     Car_informations(car_selecting);
     cout<<" Do you want to book the "<<car_info.car_model[car_selecting-1]<<"?" ;
     cout<<endl;
     cout<<endl;
     cout<<" Press ''Y'' to confirm        Press ''N'' to choose another car        Press ''E'' to exit";
     cout<<endl;
     cout<<endl;
     cout<<" Confirmation: ";
     cin>>client_confirmation;
     if  (client_confirmation=="y"  || client_confirmation=="Y")
     {
       int client_seleting=car_selecting-1;
       cout<<endl; 
       cout<<endl;
       cout<<"Note: The minimum hour for renting a car is 12 hours.";
       cout<<endl;
       cout<<endl;
       cout<<endl;
       cout<<" Enter Your Name : ";
       cin.sync();   						//To ignore anything that could be left in the stream 
       getline(cin, Client_info.client_name[client_seleting]); 
       cin.sync();
       cout<<" Enter Your Passport No: ";
       cin>>Client_info.client_passport_no[client_seleting];
       cout<<" Enter Your Driving License No: ";
       cin>>Client_info.client_license_no[client_seleting];
       cout<<" Enter Your Contact No: ";
       cin>>Client_info.client_contact_no[client_seleting];
       cout<<" Enter Your Address: ";
       cin>>Client_info.client_address[client_seleting];
       cout<<" Enter how many hours you want to rent the car: ";
       cin>>Client_info.car_hour;
       
       ofstream clientFile;
       clientFile.open ("client_info.txt", ios::app);    //text file where the client informations will be saved
       
       
        clientFile <<endl;
        clientFile <<endl;
        clientFile<<"Client Name: "<<getline(cin, Client_info.client_name[client_seleting]);
        clientFile <<endl;
        clientFile<<"Passport No: "<<Client_info.client_passport_no[client_seleting];
        clientFile <<endl;
        clientFile<<"Driving License No: "<<Client_info.client_license_no[client_seleting];
        clientFile <<endl;
        clientFile<<"Contact No: "<<Client_info.client_contact_no[client_seleting];
        clientFile <<endl;
        clientFile<<"Address: "<<Client_info.client_address[client_seleting];
        clientFile <<endl;
        clientFile<<"Hours: "<<Client_info.car_hour;
        clientFile <<endl;
        clientFile<<"Total Cost: "<<Client_info.car_hour*car_info.per_hour_rate[client_seleting];
        clientFile <<endl;
        clientFile.close();

      Invoice(client_seleting);   			//Invoice() function has been called with the parameter of client_selecting
     
      cout<<" Do you want to book another vehicle?";
      cout<<endl;
      cout<<" Press ''Y'' to confirm        Press N/E to exit";
      cout<<endl;
        cin>>client_confirmation;
        if (client_confirmation=="n" || client_confirmation=="N") 
            {
                exit;
                break;
            }
            }
            }
    return 0;
}
int user_authentication()					//A function for varifying user id and password 
{
    char id_pass;
    string user_id;
   string password;
   cout<<"This is a simple luxury car rental management system";
   cout<<endl;
   cout<<endl;
   cout<<endl;
   cout<<"The user id is 'ict' and the password is 'eop' ";
   cout<<endl;
   cout<<endl;
   cout<<"Please enter your user id and password to access our system.";
   cout<<endl;
   cout<<endl;
   cout<<endl;
   cout<<"Enter User ID: ";
   id_pass=getch();
    while(id_pass!=13)
    {
      user_id.push_back(id_pass);				//push_back function to add a new element at the end, after its current last element
      cout <<id_pass;
      id_pass = getch();
    }
    cout<<endl;
   cout <<"Enter Password: ";
   id_pass = getch();
   while(id_pass != 13)
    {
      password.push_back(id_pass);
      cout<<'*';
      id_pass=getch();
   }
   if(password=="eop" && user_id=="ict")
    {
     cout<<endl;
     cout<<endl;
     cout<<endl;
     cout << "Successfully Authenticated";
   }
   else
    {
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout << "Authentication failed";
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout << "Please enter valid user id and password";
    cout<<endl;
    cout<<endl;
    cout<<endl;
    user_authentication();
   }
}

