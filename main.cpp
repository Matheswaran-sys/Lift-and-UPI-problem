#include <bits/stdc++.h>
#define ll long long
using namespace std;
int check_enable(map<ll,int> enab,ll ph)
{
  map<ll, int>::iterator it;
  it=enab.find(ph);
  if(it==enab.end())
  {
    return 0;
  }
  if(it->second==1)
  {
    return 1;
  }
  return 0;
}

// void transfer()
// {

// }

ll check_balance(map<ll,ll> b,ll ph)
{
  map<ll,ll>::iterator it;
  it=b.find(ph);
  return it->second;
}

// void add_money()
// {

// }

int main() {
  map<ll,int> enab;
  enab.insert(pair<ll,int>(8524907907,0));
  enab.insert(pair<ll,int>(9999999999,1));
  enab.insert(pair<ll,int>(8524907906,1));
  enab.insert(pair<ll,int>(8524907905,1));
  enab.insert(pair<ll,int>(8524907904,1));
  map<ll,int> trans_count;
  trans_count.insert(pair<ll,int>(8524907907,0));
  trans_count.insert(pair<ll,int>(9999999999,0));
  trans_count.insert(pair<ll,int>(8524907906,0));
  trans_count.insert(pair<ll,int>(8524907905,0));
  trans_count.insert(pair<ll,int>(8524907904,0));
  map<ll,ll> trans_amount;
  trans_amount.insert(pair<ll,ll>(8524907907,0));
  trans_amount.insert(pair<ll,ll>(9999999999,0));
  trans_amount.insert(pair<ll,ll>(8524907906,0));
  trans_amount.insert(pair<ll,ll>(8524907905,0));
  trans_amount.insert(pair<ll,ll>(8524907904,0));
  map<ll,ll> balance;
  balance.insert(pair<ll,ll>(8524907907,100000));
  balance.insert(pair<ll,ll>(9999999999,20000));
  balance.insert(pair<ll,ll>(8524907906,30000));
  balance.insert(pair<ll,ll>(8524907905,3000));
  balance.insert(pair<ll,ll>(8524907904,2000));
  int n;

  do{
    
    cout << "\nEnter 0 to exit!" << endl;
    cout << "1.Enable/Disable UPI" << endl;
    cout << "2.Transfer amount" << endl;
    cout << "3.Check Balance" << endl;
    cout << "4.Add money" << endl;
    cin>>n;
    
    if(n==1)
    {
      ll ph;
      cout << "Enter the mobile number : \n";
      cin >> ph;
      map<ll, int>::iterator it;
      it=enab.find(ph);
      int t;
      if(it!=enab.end())
      {
        do{
          cout << "\nEnter 0 to exit!" << endl;
          cout << "1.Enable" << endl;
          cout << "2.Disable" << endl;
          cin >> t;
          if(t==1)
          {
            it->second=1;
            cout << "Enabled !!\n"; 
            cout << it->second ;
            t=0;
          }
          else{
            it->second=0;
            cout << "Disabled !!\n";
            t=0;
          }
        }while(t!=0);

      }
      else
      {
        cout << "Not Found!";
      }
      
    }
    else if(n==2)
    {
      ll sph,rph,amount;
      cout << "\n Enter the sender mobile number:\n";
      cin >> sph;
      cout << "\n Enter the receiver mobile number:\n";
      cin >> rph;
      cout << "\n Enter the amount:\n";
      cin >> amount;
      map<ll,int>::iterator it2;
      it2=trans_count.find(sph);
      map<ll,ll>::iterator it3;
      it3=trans_amount.find(sph);
      if(it3->second + amount <= 50000)
      {
      if(it2->second<3)
      {
      if(check_enable(enab,sph) && check_enable(enab,rph))
      {
        ll sbal=check_balance(balance, sph);
        ll rbal=check_balance(balance, rph);
        
        if(sbal >= amount)
        {
          if(amount<=20000)
          {
          if(rbal+amount<=100000)
          {
            map<ll,ll>::iterator it;
            it=balance.find(rph);
            it->second+=amount;
            map<ll,ll>::iterator it1;
            it1=balance.find(sph);
            it1->second-=amount;
            cout << "Transferred successfully!";

            
            it2->second++;
            it3->second+=amount;
          }
          else
          {
            cout << "Reciever's account can't hold more than one lakh\n"; 
          }
          }
          else
          {
          cout << "Maximum Transcation amount can be 20000";
          }
          
        }
        else
        {
          cout << "Insufficient balance!\n";
        }
      }
      else
          {
            cout << "Check the sender/receiver phone number!\n";
          }
      
      
      }
      else
      {
        cout<<"Maximum transaction limit reached!\n";
      }
      }
      else
      {
        cout << "Maximum transaction amount per day is 50000\n";
      }
    }
    else if(n==3)
    {
      ll ph;
      cout << "Enter the mobile number: \n";
      cin >> ph;
      if(check_enable(enab,ph)==0)
      {
        cout << "Account either diabled/not found!!\n";
      }
      else{
        ll res=check_balance(balance,ph);
        cout << "Your balance is " << res << endl;
      }
    }
    else if(n==4)
    {
      ll ph;
      cout << "\n Enter the mobile number:\n";
      cin >> ph;
      if(check_enable(enab,ph)==1)
      {
        ll amount;
        cout << "\n Enter the amount:\n";
        cin >> amount;
        if((amount+check_balance(balance,ph))>100000)
        {
          cout << "Account can hold upto one lakh only\n";
          ll res=check_balance(balance,ph);
          cout << "Your balance is " << res << endl;
        }
        else
        {
          map<ll,ll>::iterator it;
          it=balance.find(ph);
          it->second+=amount;
          cout << "Amount added successfully!!";
        }
      }
      else
      {
        cout << "Account either disabled/not found";
      }
    }
  }while(n!=0);

  
}