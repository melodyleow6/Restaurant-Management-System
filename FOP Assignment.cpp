#include<iostream> 
#include<string>
using namespace std; 

void displayMenu() 
{
 cout<<"============================================================Menu======================================================================"<<endl;
 cout<<"Main Dishes"<<endl;
 cout<<"   Number    ||           Name            ||                      Description                                        ||  Price (RM) "<<endl;
 cout<<"------------------------------------------------------------------------------------------------------------------------------------"<<endl;
 cout<<"     (1)     ||   Smoky Duck Aglio Olio   ||  Spaghetti with smoked duck, garlic, olive oil, and chili flakes        ||  26.00    "<<endl;
 cout<<"     (2)     ||   Creamy Dream Pasta      ||  Creamy fettuccine with grilled chicken and parmesan                    ||  28.00    "<<endl;
 cout<<"     (3)     ||   Cheesy Meltwich         ||  Buttery toast filled with melted cheddar cheese                        ||  15.00    "<<endl;
 cout<<"     (4)     ||   Morning Eggwich         ||  Soft bread filled with scrambled eggs and cheddar                      ||  17.00    "<<endl;
 cout<<"     (5)     ||   Double Chicken Burger   ||  Two juicy chicken patties stacked with melted cheese                   ||  18.00    "<<endl;
 cout<<"     (6)     ||   Dreamy Big Breakfast    ||  Sausage, eggs, toast, hash browns, and grilled tomato on happy plates  ||  38.00    "<<endl;
 cout<<"------------------------------------------------------------------------------------------------------------------------------------"<<endl;
 cout<<"Snacks"<<endl;
 cout<<"    Number   ||               Name        ||                      Description                                        ||  Price (RM) "<<endl;
 cout<<"------------------------------------------------------------------------------------------------------------------------------------"<<endl;
 cout<<"     (1)     ||   Golden Fries            ||  Crispy fries sprinkled with sea salt                                   ||  13.00    "<<endl;
 cout<<"     (2)     ||   Happy Nugget Box        ||  Crispy chicken nuggets served with your favorite dip                   ||  15.00    "<<endl;
 cout<<"     (3)     ||   Onion Halo Rings        ||  Golden onion rings served with creamy mayo dip                         ||  14.00    "<<endl;
 cout<<"     (4)     ||   Popcorn Chickens        ||  Bite-sized fried chicken — crispy outside, tender inside               ||  16.00    "<<endl;
 cout<<"------------------------------------------------------------------------------------------------------------------------------------"<<endl;
 cout<<"Dessert"<<endl;
 cout<<"   Number    ||          Name             ||                      Description                                        ||  Price (RM)"<<endl;
 cout<<"------------------------------------------------------------------------------------------------------------------------------------"<<endl;
 cout<<"     (1)     ||   Berry Sweet Cheesecake  ||  Smooth cheesecake topped with juicy strawberries                       ||  14.00    "<<endl;
 cout<<"     (2)     ||   Tiramisu Dream Cup      ||  Soft coffee-soaked layers of mascarpone and cocoa dust                 ||  15.00    "<<endl;
 cout<<"     (3)     ||   Mini Brownie Smiles     ||  Cute little fudgy brownies — perfect for sharing!                      ||  9.00    "<<endl;
 cout<<"     (4)     ||   Waffle Wonderland       ||  Golden waffles topped with ice cream and powdered sugar                ||  16.00    "<<endl;
 cout<<"------------------------------------------------------------------------------------------------------------------------------------"<<endl;
 cout<<"Beverage"<<endl;
 cout<<"    Number   ||       Name                ||                      Description                                        ||  Price (RM)"<<endl;
 cout<<"------------------------------------------------------------------------------------------------------------------------------------"<<endl;
 cout<<"     (1)     ||   Berry Sweet Cheesecake  ||  Smooth cheesecake topped with juicy strawberries                       ||  14.00    "<<endl;
 cout<<"     (2)     ||   Tiramisu Dream Cup      ||  Soft coffee-soaked layers of mascarpone and cocoa dust                 ||  15.00    "<<endl;
 cout<<"     (3)     ||   Mini Brownie Smiles     ||  Cute little fudgy brownies — perfect for sharing!                      ||  9.00    "<<endl;
 cout<<"     (4)     ||   Waffle Wonderland       ||  Golden waffles topped with ice cream and powdered sugar                ||  16.00    "<<endl;
 cout<<"------------------------------------------------------------------------------------------------------------------------------------"<<endl;
}

// char searchItem ()
// {

// }

int main()
{
  int num ; 
  cout<<"=============================Welcome to MWC=============================="<<endl; 
  do 
  {
    cout<<"Enter (1) as Customer " <<endl; 
    cout<<"Enter (2) as Manager Login" <<endl; 
    cout<<"========================================================================"<<endl;
    cout<<"Enter your option"<<endl; 
    cin>>num;  
    
    if(num <1 or num>2) 
    {
        cout<<"Kindly Enter a valid number"<<endl; 
    }
  }
    while (num<1 or num>2); 
   
   
  int table , pax ; 
  int option; 
  if(num == 1) 
  {
    cout<<"Enter table number: ";
    cin>>table ; 
    cout<<"Enter number of pax:"; 
    cin>>pax ; 
    cout<<endl;
    
    do 
    {
    cout<<"Enter (1) to Display Menu"<<endl;
    cout<<"Enter (2) to Place order"<<endl;
    cout<<"Enter (3) to Print Receipt"<<endl;
    cout<<"Enter (4) to Exit"<<endl; 
    cin>>option; 
    
    if(option<1 or option>4)
    {
        cout<<"Please enter a valid number"<<endl;
    }
    }
    while(option<1 or option>4); 
    
    int value; 
    switch(option)
    {
    case 1 :displayMenu();
            
            do 
            {
            cout<<"Enter (1) to place order:"<<endl;
            cout<<"Enter (2) to return to Homepage"<<endl;
            cin>>value; 
            }
            while(value<1 or value >2);
            
            break ;
    
    }
  }
}
