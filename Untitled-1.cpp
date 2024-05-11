#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;

void login();
void registeration();
void forgot();

int main()
{
    int n;

    cout<<"\t\t\t_______________________________________________________________\n\n\n";
    cout<<"\t\t\t                     WelCome To Login Page                      \n\n\n";
    cout<<"\t\t\t______________________________MENU_______________________________\n\n";
    cout<<"                                                                        \n\n";
    cout<<endl;

    cout<<"\t\t\t |      Press 1 To Login                                        |"<<endl;
    cout<<"\t\t\t |      Press 2 To Register                                     |"<<endl;
    cout<<"\t\t\t |      Press 3 To Forgot                                       |"<<endl;
    cout<<"\t\t\t |      Press 4 To Exit                                         |\n\n"<<endl;

    cout<<"\t\t\t       Enter Your Choice: ";
    cin>>n;
    cout<<endl;

    switch(n)
    {
        case 1:
        system("cls");
        login();
        break;

        case 2:
        system("cls");
        registeration();
        break;

        case 3:
        system("cls");
        forgot();
        break;

        case 4:
        cout<<"\t\t\t      ThankYou For Visiting \n\n";
        break;

        default:
        system("cls");
        cout<<"\t\t\t\tSelect Valid Option \n\n";
        main();
    }
    return 0;
}


void login()
{
    int count;
    string user_id, password, id, pass;
    // system("cls");

    cout<<"\t\t\t Enter Username And Password \n\n";
    cout<<"\t\t\t UserName: ";
    cin>>user_id;
    cout<<"\t\t\t Password: ";
    cin>>password;

    ifstream input("records.txt");

    while(input>>id>>pass)
    {
        if(id==user_id && pass==password)
        {
            count=1;
            system("cls");
        }
    }
    input.close();
    if(count == 1)
    {
        cout<<"\n\t\t\t Login is Successful  \n";
        main();
    }
    else{
        system("cls");
        cout<<"\n\t\t\t Login Error \n\t Please Check Your Username and Password \n\n\n";
        login();
    }

}

void registeration()
{
    system("cls");
    int count;
    string ruser_id, rpassword, id, pass;
    
    cout<<"\t\t\t Enter Username: ";
    cin>>ruser_id;
    cout<<"\t\t\t Enter Password: ";
    cin>>rpassword;

    ofstream f1("records.txt", ios::app);
    f1<<ruser_id<<' '<<rpassword;
    system("cls");

    cout<<"\n\t\t\t Registeration Successfull \n\n";
    main();
}

void forgot()
{
    int option;
    // system("cls");

    cout<<"\n\t\t\t Forgot Your Password \n";
    cout<<endl;
    cout<<"\t\t\t Press 1 To Find Your Password \n";
    cout<<"\t\t\t Press 2 For Main Menu \n";
    cout<<"\t\t\t       ";
    cin>>option;

    switch(option)
    {
        case 1:
        {
            int count =0;
            string fuser_id, sid, spass;
            cout<<"\n\t\t\t Enter Username: ";
            cin>>fuser_id;

            ifstream f2("records.txt");

            while(f2>>sid>>spass)
            {
                if(sid==fuser_id)
                {
                    count = 1;
                } 
            }
            f2.close();
            if(count==1)
            {
                system("cls");
                cout<<"\n\t\t\t Your Password is: "<<spass<<"\n\n";
                main();
            }
            else{
                cout<<"\n\t\t\t Sorry! Your Account Is Not Found \n\n";
                forgot();
                system("cls");
            }
            break;
        }
    

        case 2:
        {
            main();
            break;
        }

        default:
        cout<<"\n\t\t\t Wrong! Choice Please Try Again! \n\n";
        forgot();
    }

}


