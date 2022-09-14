 #include <iostream>
 #include <fstream>
 using namespace std;
 class shopping
 {
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
    
 };
 void shopping :: menu()
 {
    int choice ;
    string email;
    string password;
    cout<<"\t\t\t\t_______________________________\n";
    cout<<"\t\t\t\t                               \n";
    cout<<"\t\t\t\t  supermarket main menu        \n";
    cout<<"\t\t\t\t                               \n";
    cout<<"\t\t\t\t_______________________________\n";
    cout<<"\t\t\t\t                               \n";
    cout<<"\t\t\t\t|  1) Administrator           |\n";
    cout<<"\t\t\t\t|                             |\n";
    cout<<"\t\t\t\t|  2) Buyer                   |\n";
    cout<<"\t\t\t\t|                             |\n";
    cout<<"\t\t\t\t|  3) Exit                    |\n";
    cout<<"\t\t\t\t|                             |\n";
    cout<<"\t\t\t\t|  Please select              |\n";
cin>>choice;

switch(choice)
{ 
    m:
    case 1:
    cout<<"\t\t\t please login \n";
    cout<<"\t\t\t enter email  \n";
    cin>>email;
    cout<<"\t\t\t enter paasword \n";
    cin>>password;

    if(email=="chetnasri.vas@gmail.com"&& password=="chetna")
    {
        administrator();
    }
    else{
        cout<<"invalid email/password";
    }
    break;
   
    case 2:
    {
    buyer();
    }
    case 3:
    {
        exit(0);
    }
    defaulat:
    {
        cout<<"Please select from the given option";
    }
}
    goto m;
 
 }
 void shopping :: administrator()
 {
    m:
    int choice;
    cout<<"\n\t\t\t Administrator menu";
    cout<<"\n\t\t\t ___1) Add the product____|";
    cout<<"\n\t\t\t                          |";
    cout<<"\n\t\t\t __2) Modify the product__|";
    cout<<"\n\t\t\t                          |";
    cout<<"\n\t\t\t__3) Delete the product___|";
    cout<<"\n\t\t\t                          |";
    cout<<"\n\t\t\t__4) Back to main menu____|";

    cout<<"\n\t\t\t   Please enter your choice ";

    cin>>choice;

    switch(choice)
    {
        case 1:
        add();
        break;
        case 2:
        edit();
        break;
        case 3:
        rem();
        break;
        case 4:
        menu();
        break;
default:
cout<<"Invalid choice";
    } 
    goto m;
 }
 void shopping :: buyer()
 {
    m:
    int choice;
    cout<<"\n\t\t___Buyer___";
    cout<<"\n\t\t____________";
    cout<<"\n\t\t 1) Buy product ";
    cout<<"\n\t\t____________";
    cout<<"\n\t\t 2) Go back ";
    cout<<"\n\t\t enter your choice:";
    cin>>choice;

    switch(choice)
    {
        case 1:
       receipt();
       break;
       case 2:
       menu();
       break;
       default :
       cout<<"Invalid choice";
    }
    goto m;

 } 

 void shopping:: add()
 {
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\n\t\t Add new product ";
    cout<<"\n\t\t Product code of the product ";
    cin>>pcode;
    cout<<"\n\t\t Name of the product ";
    cin>>pname;
    cout<<"\n\t\t Price of the product ";
    cin>>price;
    cout<<"\n\t\t Discount on product";
    cin>>dis;


    data.open("database.txt",ios::in);
     if(!data)
     {
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
     }
     else
     {
        data>>c>>n>>p>>d;
        while(!data.eof())
        {
            if(c==pcode)
            {
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
        if (token==1)
        goto m;
        else{
             data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();

        }
     }
     cout<<"\n\n\t Record inserted !";
 }
 void shopping:: edit()
 {
    fstream data,data1;
    int pkey;
    int token;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t Modify the record ";
    cout<<" \n\t\t product code: ";
    cin>> pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n file does not exist!";

    }
    else{
        data1.open("database.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\n product new code:";
                cin>>c;
                cout<<"\n\nName of the product:";
                cin>>n;
                cout<<"\n\n Price";
                cin>>p;
                cout<<"\n\n Discount:";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n Record edited";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<" \n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","databse.txt");

        if(token==0)
        {
            cout<<"\n\n Record not found sorry!";
        }
    }
 }
 void shopping:: rem()
 {
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t Delete product";
    cout<<"\n\n\t  Product code";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n file not exist";
    }
    else{
        data1.open("database.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>price>>dis;
        while(!data.eof())
        {
            if(pcode==pkey)
            {
                cout<<"\n\n\t Delete successfully!";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";

            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");
        if(token==0)
        {
            cout<<"\n\n\t Record not found";
        }
    }
 } 

 void shopping::list()
 {
    fstream data;
    cout<<"\n\n______________________________\n";
    cout<<" product no.\t\tName\t\tPrice\n";
    cout<<"\n\n|______________________________\n";
    data.open("database.txt",ios::in);
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
        cout<<pcode<<pname<<price<<dis<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
 }

 void shopping ::receipt()
 { 
    m:
    fstream data;
    int arrc[100];
    int arrq[100];
    string choice;
    int c=0;
    float amount=0;
    float dis=0;
    float total=0;
    cout<<"\n\n\t\t RECEIPT";
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n  Empty database";
    }
    else{
        data.close();
        list();
        cout<<"\n_________________________\n";
        cout<<"\n                         \n";
        cout<<"\n   Place the order       \n";
        cout<<"\n                         \n";
        cout<<"\n_________________________\n";

        do{
            cout<<"\nEnter the code:";
            cin>>arrc[c];
            cout<<"\nEnter the product quantity:";
            cin>>arrq[c];
            for(int i=0;i<c;i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"\n\nDuplicate product code!  please try again";
                    goto m;
                }

                }
                c++;
                cout<<"\n\n do you want to buy another product? if yes then press y else no";
                cin>>choice;
            }
            while(choice=="y");
            cout<<"\n\n____________________RECEIPT_______________\n";
            cout<<"\nproduct no\t product name\t product quantity\t price\t amount\t amount with discount\n";

            for(int i=0;i<c;i++)
            {
                data.open("database.txt",ios::in);
                data>>pcode>>pname>>price>>dis;
                while(!data.eof())
                {
                    if(pcode==arrc[i])
                    {
                    amount=price*arrq[i];
                    dis=amount-(amount*dis/100);
                    total=total+dis;
                    cout<<"\n"<<pcode<<"\t"<<pname<<"\t"<<arrq[i]<<"\n"<<amount<<"\n"<<dis;

                }
                data>>pcode>>pname>>price>>dis;
            }
            }
            data.close();
        }
        cout<<"\n\n_____________________";
        cout<<"\n Total amount:"<<total;
 
 }
 int main()
 {
    shopping s;
    s.menu();
 
 return 0;
 }
