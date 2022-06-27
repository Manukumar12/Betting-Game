
#include<bits/stdc++.h>
#include<ctime>
#include <climits>
using namespace std;
void Message()
{
    cout << "\n\n\n\n\n";
    cout << "\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n";
    cout << "\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
    cout << "\n\t\t\t        =                                           =";
    cout << "\n\t\t\t        =                    WELCOME                =";
    cout << "\n\t\t\t        =                      TO                   =";
    cout << "\n\t\t\t        =                 BETTING GAME              =";
    cout << "\n\t\t\t        =                                           =";
    cout << "\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
    cout << "\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n";
    cout << "\n\n\n\t\t\t Enter any key to continue.....";
    system("pause");
}
void rules()
{
    system("cls");
    cout << "\t\t======BETTING NUMBER GUESSING RULES!======\n";
    cout << "\t1. Choose a number between 1 to 10\n";
    cout << "\t2. Winner gets 10 times of the money bet\n";
    cout << "\t3. Wrong bet, and you lose the amount you bet\n\n";
}
int func1(int a,int b,string n)
{
    cout << "Betting balance can't be more than current balance!\n"
                       <<"\nRe-enter betting amount\n ";
                        cout<<"Hey, "<<n<<", enter amount to bet :$";
                cin>>b;
                if(a>b)
                return b;
                else
                func1(a,b,n);
}
int func2(int g)
{   
     cout << "\nNumber should be between 1 to 10\n"
                    <<"Re-enter number:\n ";
                      cout << "/n Guess any betting number between 1 & 10 :";
              cin >>g;
              if(g<= 0 || g> 10)
              return func2(g);
              else 
              return g;

}


int main()
{   Message();
    string name;
    int balance,bet_amount,guess,outcome;
    char choice;
    srand(time(0));
    cout << "\n\nWhat's your Name : ";
    getline(cin, name);
    cout << "\n\nEnter the starting balance to play game : $";
    cin >> balance;
   while (cin.fail())
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "You can only enter numbers.\n";
        cout << "Enter a number.\n";
        cin >> balance;
    } 
   
   int t=1;
   while(t--)
   {
       system("cls");
       rules();

       cout<<"\n\nYour current balance is $ " << balance << endl;
       cout<<"Hey, "<<name<<", enter amount to bet :$";
       cin>>bet_amount;
      
       if(bet_amount>balance)
       {
         bet_amount= func1(balance,bet_amount,name);
         
       }

       cout << "/n Guess any betting number between 1 & 10 :";
            cin >> guess;
            if(guess <= 0 || guess > 10)
            {
                guess=func2(guess);
            }

             outcome=rand()%10+1;// random number choosed by system

             if(guess==outcome)
             {
                 cout<<"\n\nYAY! You are in luck!! You have won Rs." << bet_amount * 10;
            balance = balance + bet_amount * 10;
        }
        else
        {
            cout << "Oops, better luck next time !! You lost $ "<< bet_amount <<"\n";
            balance = balance - bet_amount;
        }
        cout << "\nThe winning number was : " << outcome <<"\n";
        cout << "\n"<<name<<", You have balance of $ " << balance << "\n";
        if(balance == 0)
        {
            cout << "You have no money to play ";
            break;
        }

        cout<<"\n\n-->Do you want to play again (y/n)? ";
        cin >> choice;

        if(choice=='y'|| choice=='Y')
         t++;
         else
          continue;
     }
      cout << "\n\n\n";
    cout << "\n\nThanks for playing the game./n Your balance is $ " << balance << "\n\n";
        return 0;

 }


