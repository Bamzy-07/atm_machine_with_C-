#include <iostream>

/* Author: Bamiebo Obed Numbo
   Program: C++ code for an ATM. */

using namespace std;

//Class for ATM program

class ATM{
   public:
    void display();
    void account();
    void deposit();
    void withdrawal();
    void checkBalance();
    void changePin();
    ATM();

   private:
    float amount;
    int defaultPin;
   };

int main()
{
    ATM myATM;
    int choice;
    int service;

    cout<<"Welcome to our ATM Banking service, enter any number to continue or 9 to exit: ";
    cin>>choice;


    while(choice!= 9){
            myATM.account();
            cin>>service;
        switch(service){
        case 1:
            myATM.deposit();
            cout<< "Enter any number to continue or 9 to exit: ";
            cin>>choice;
            break;
        case 2:
            myATM.withdrawal();
            cout<< "Enter any number to continue or 9 to exit: ";
            cin>>choice;
            break;
        case 3:
            myATM.checkBalance();
            cout<< "Enter any number to continue or 9 to exit: ";
            cin>>choice;
            break;
        case 4:
            myATM.changePin();
            cout<< "Enter any number to continue or 9 to exit: ";
            cin>>choice;
        default:
            cout<< "Invalid selection,Enter any number to continue or 9 to exit: ";
            cin>>choice;
            break;

        }

    }

    cout<< "Thank you for banking with Us "<<endl;

    return 0;
}

//Function definitions

void ATM::display(){
    cout<<"How may we assist you today, "<<endl;
    cout<<" 1. Deposit "<<endl;
    cout<<" 2. Withdrawal "<<endl;
    cout<<" 3. Check Balance "<<endl;
    cout<<" 4. Change Pin "<<endl;
    cout<< "Enter your option: ";

}

void ATM::deposit(){
    float depositAmt;
    cout<<"Enter amount you want to deposit: ";
    cin>>depositAmt;

    if(depositAmt < 0){
        cout<<"Please enter a valid amount"<<endl;
        cin >>depositAmt;
    }
    else if(depositAmt >=0){
        cout<<"You have deposited "<<depositAmt<<" cedis"<<endl;
        amount = amount + depositAmt;
    }
    else{
        cout<<"Please take your card and try again, Thank you!"<<endl;
    }


    cout<<"Your current balance is "<<amount<<" cedis"<<endl;

}

void ATM::withdrawal(){
    float withdrawalAmt;

    cout<<"Enter amount you want to withdraw: ";
    cin>>withdrawalAmt;

    if(amount < withdrawalAmt){
        cout<<"Sorry you can't withdraw "<<withdrawalAmt<<"cedis"<<endl;
        cout<<"Your current Balance is "<<amount<<"cedis"<<endl;
    }
    else if(amount > withdrawalAmt){
        cout<< "You have withdrawn "<< withdrawalAmt << "cedis"<<endl;
        amount = amount - withdrawalAmt;
        cout<< "Your current balance is "<< amount << "cedis"<<endl;
    }
    else
        cout << "Invalid amount, Take your card and try again, Thank you!" <<endl;

}

void ATM::checkBalance(){
    cout<< "Your current balance is "<<amount << "cedis" << endl;

}

ATM::ATM(){
    amount = 0.0;
    defaultPin = 1234;
}

void ATM::account(){
    int pin;
    cout<< "\nPlease enter your pin: ";
    cin >> pin;

    if(pin >0){
        if(pin != defaultPin){
            cout<< "Your pin is incorrect, Enter your pin again: ";
            cin >> pin;
        }
        if(pin == defaultPin){
            display();
        }
        else{
            cout<< "Incorrect Pin, Take your Card and try again"<<endl;
        }

    }else
    cout<< "Invalid Pin Number"<<endl;
}

void ATM::changePin(){
    int oldPin;
    int newPin;
    cout<< "Enter your old pin: ";
    cin>>oldPin;

    if(oldPin > 0){
        if(oldPin != defaultPin){
            cout<< "Pin Mismatch, Try again: ";
            cin>>oldPin;
        }
        if(oldPin == defaultPin){
            cout<< "Enter your new Pin: ";
            cin>> newPin;

            cout<< "Your Pin is changed"<<endl;
            defaultPin = newPin;

        }
        else{
            cout<< "Pin Mismatch, Take your card and try again"<<endl;
        }
    }
    else
        cout<< "Invalid Pin"<<endl;
}
