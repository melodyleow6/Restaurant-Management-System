#include <iostream> 
#include <fstream>
#include <sstream>
#include <ctime>
#include<iomanip>

using namespace std;

// totalBill is to total , orderNum is ordernumber , payment is payment method 

//dailysalrs and montly sales


// check if file is empty 
bool emptyFile(const string& fname)
{
    ifstream file(fname);
    return file.peek()== EOF ; 
}

// to write a order header if empty 
void OrderHeader()
{
 

    if(emptyFile("orderSales.txt"))
    {
        ofstream myFile("orderSales.txt",ios::app);
        if (!myFile)
        {
            cerr<<"Error: cannot open oder.txt !" <<endl; 
            return; 
         }
        else 
        {
            myFile<<"-------------------------------------------------------------------------------------------\n";
            myFile<< "||  Order Number  ||      Order Date & Time       ||  Total (RM)  ||    Payment Method  ||\n";
            myFile<< "------------------------------------------------------------------------------------------\n";
            myFile.close();
        }
    }
}

// to write daily sales header if empty 
void dailySalesheader ()
{
    if(emptyFile("dailySales.txt"))
    {
      ofstream myFile("dailySales.txt", ios::app);
      if(!myFile)
      {
          cerr<<"Error: cannot open dailySales.txt !" <<endl; 
          return;
      }
      else
      {
          myFile<<"------------------------------------\n"; 
          myFile<<"||   Date & Time   ||   Sales   ||\n";
          myFile<<"------------------------------------\n";
          myFile.close();
      }
    }
}

// to write monthly sales header if empty 
void monthlySalesheader()
{
    if(emptyFile("monthlySales.txt"))
    {
        ofstream myFile("monthlySales.txt", ios::app);
        if(!myFile)
        {
            cerr<<"Error: cannot open monthlySales.txt !" <<endl;
            return;
        }
        else
        {
            myFile<<"------------------------------------\n";
            myFile<<"||   Date & Time   ||   Sales   ||\n";
            myFile<<"------------------------------------\n";
            myFile.close();
        }
    }
}

// store order data to file 
void storeOrderdata(int orderNum , double totalBill , string payment)
{
    time_t timeNow = time(NULL); 
    tm *today = localtime(&timeNow);
    
    
    ofstream myFile("orderSales.txt", ios::app);
    
    if(!myFile) // file failed to open 
    {
      cerr<<"Error : Cannot open oderSales.txt"<<endl; 
      return; 
    }
    
    //write the order data 
    myFile <<""<< "#" << orderNum  <<" "
    << put_time(today, "%d/%m/%Y") <<"  "
    << put_time(today,"%a") << "  "
    << put_time(today,"%H:%M:%S") << "  "
    << fixed<< setprecision(2) <<  totalBill  <<"  "
    <<  payment  <<endl; 
    
    myFile.close();
    
    cout<< "Order recorded successfully !"<<endl;
           
    
}

//automatic daily sales calculation 
void storeDailydata()
{   
    //to get today's date 
    time_t timeNow = time(NULL); 
    tm*today = localtime(&timeNow);
    int day = today->tm_mday;
    int month = today->tm_mon + 1 ; // month ( 0-11, so +1 for 1-12) 
    int year =today->tm_year + 1900; // years since 1900
    
    //read oderSales.txt and sum today's order 
    ifstream myFile("orderSales.txt");
        if(!myFile)
        {
            cerr << "Error! cannot open orderSales.txt";
            return; 
        }
    
    double totalDailysales = 0.00 ; 
    string line ; // declare variable line to store one line of text at at time from a file 
    while (getline(myFile, line /*read one line from the file orderSales into line */))  //keep reading each line until the end 
    {
        // this whole thing is to break a sentence into a word so i can take out the date seperately 
        stringstream ss(line); // turn the string into stream so can use >> 
        string hash , orderNum , dateStr  , timeStr , totalBill , payment ; 
        ss>> hash >> orderNum >> dateStr >> timeStr >> totalBill >> payment ; // break the sentence into pieces so can work each individually 
        
        int d , m , y ; 
        char slash1 ,slash2 ; 
        
        stringstream sd(dateStr);
        sd >> d >> slash1 >> m >> slash2 >> y ;
        
        if (d== day && m== month && y== year )
        {
            totalDailysales += stod(totalBill); // string to double 
        }
    }
    myFile.close(); 
    
    
    // write today's total into dailySales.txt 
    ofstream dailyFile("dailySales.txt", ios::app);
    
    if(!dailyFile)
    {
        cerr<<"Error : Cannot open dailySales.txt"<<endl;
        return;
    }
    
    dailyFile<<"\t" <<put_time(today,"%d/%m/%Y" ) <<"\t"<<"RM"
          <<fixed <<setprecision(2)<<totalDailysales <<endl;
    
    
    dailyFile.close();
    
    cout<<"Daily sales updated successfully"<<endl; 
           
    
}

// automatic monthly sales calculation 
void storeMonthlydata()
{
   
  time_t timeNow = time(NULL); 
  tm*today= localtime(&timeNow); 
  int currentMonth = today->tm_mon+ 1; 
  int currentYear = today->tm_year + 1900; 
   
  ifstream myFile("orderSales.txt");
  if(!myFile)
  {
      cerr<< "Error: cannot open orderSales.txt" <<endl; 
      return; 
  }
   
  double totalMonthlysales = 0.00 ; 
  string line ;
   
  while(getline(myFile , line))
  {
     stringstream ss(line);
     string hash , orderNum , dateStr ,timeStr , totalBill , payment ; 
     ss>> hash >> orderNum >> dateStr  >> timeStr >> totalBill >> payment ;
     
     int date , month , year ; 
     char slash1 , slash2 ; 
     
     stringstream sm(dateStr);
     sm>> date >> slash1 >> month >> slash2 >> year ; 
     
   
   
  if(month == currentMonth && year == currentYear)
  {
      totalMonthlysales += stod(totalBill);
  }
   
  }
   
  myFile.close();
  
  ofstream dailyFile("monthlySales.txt",ios::app);
  if(!dailyFile)
  {
      cerr<<"Error: cannot open monthlySales.txt"<<endl; 
      return;
  }
  
  dailyFile<<"\t"<<put_time(today,"%m/%Y")<<"\t"<<"RM"
          <<fixed <<setprecision(2)<<totalMonthlysales <<endl; 
          
  dailyFile.close();
  
  cout<< "Monthly sales updated successfully"<<endl; 
  
}


void displayFile(const string &fileType)// a string that i can read but wont change
{
    ifstream myFile(fileType);
    if(!myFile)
    {
        cerr << "Error ! Cannot open file" << fileType <<endl; 
        return; 
    }
    
    string line ; 
    while(getline(myFile , line))
    {
        cout<< line << endl; 
    }
    myFile.close(); 
}

void manageSales()
{
  int option =1 ; 
  while (option !=0)
  {
      cout<<"------Manage Stock Sales-------"<<endl;
      cout<<"(1) Check Sales History"<<endl; 
      cout<<"(2) Check Daily Sales"<<endl; 
      cout<<"(3) Check Monthly Sales"<<endl;
      cout<<"(0) Exit to the Main Menu"<<endl; 
      cout<<"Option :";
      cin>>option;
      
      switch(option)
      {
          case 0 :
                break; 
          case 1 :
                displayFile("orderSales.txt");
                break; 
          case 2 : 
                displayFile("dailySales.txt");
                break; 
          case 3 : 
                displayFile("monthlySales.txt");
                break; 
          default:
                cout<< "Invalid Option ! Please Try Again" ;
                break; 
                
      }
  }
}




// payment option 
 
string paymentMethod(double totalBill)
{
    int payment ; 
    do
    {
    cout<<"=================Choose your payment method================"<<endl;
    cout<<"(1) Cash Payment"<<endl;
    cout<<"(2) Card Payment "<<endl;
    cout<<"(3) E-Wallet Payment"<<endl; 
    
    cout<<"Please enter your payment method :";
    cin>>payment;
    
    if(payment<1 || payment >3)
        {
          cout << "Invalid payment method. Please enter a valid number !"<<endl; 
        }
    }while(payment<1 || payment >3);
    
    switch(payment)
    {
        case 1 :
        cout<<"Please pay RM"<< totalBill << " at the counter. Thank you !"<<endl; 
        return "Cash" ; 
        
        case 2 :
        cout<<"Please tap or swipe your card to complete payment. Thank you !"<<endl;
        return "Card" ; 
        
        case 3: 
        cout <<"Please scan the QR"<<endl; 
        return "QR" ;
    }
}

int main()
{
    OrderHeader();
    dailySalesheader();
    monthlySalesheader();
    
    
    int option ; 
    cout<<"enter 1 to see receipt 2 to manage sales";
    cin>>option; 
    
    
    //calculate payment
    double total = 0.00;
    double tax ;
    double subtotal=23.00 ; 
    int numOrder= 0; 

    switch(option)
    {   
    case 1 :
    {
    if(subtotal==0)
    {
        cout<<"Theres no item placed "<<endl; 
    }
    else
    {
      numOrder++ ;
      cout<<"---------------------------------------------------------"<<endl;
      cout<<"                       Receipt                           "<<endl;
      cout<<"---------------------------------------------------------"<<endl; 
    
    tax = subtotal * 0.06 ; 
    total = subtotal + tax ;
      cout<<"Order Number : #" <<numOrder <<endl; 
      cout<< fixed << setprecision(2); 
      cout<<"Sub total : RM" << subtotal <<endl;
      cout<<endl; 
      cout<<"Service Tax (6%) : RM" <<tax <<endl; 
      cout<<"-----------------------------------------------------------"<<endl; 
      cout<<"Total :RM" << total<<endl;
      cout<<"-----------------------------------------------------------"<<endl;
      cout<<endl;
      time_t timeNow = time(NULL); 
      tm*today= localtime(&timeNow);
      cout<<" Date and Time :"<<put_time(today, "%Y-%m-%d %H:%M:%S")<<endl;
      string methodUsed = paymentMethod(total);
      storeOrderdata(numOrder, total ,methodUsed );
      storeDailydata();
      storeMonthlydata();
      cout<<"---------------------------------------------------------"<<endl;
      cout<<"              Thank You ! See You Next time              "<<endl;
      cout<<"---------------------------------------------------------"<<endl;
      
     break;
    }
    }
    case 2 :
    {
        cout<<"Manage Daily and Monthly Sales :" <<endl; 
        manageSales();
        break;
    }
    }
}
