#include<iostream>
#include<string>
using namespace std;
int main()
{
  string station;
  cin>>station;
  if(station[0] == station[1] && station[1] == station[2])
    cout<<"No"<<endl;
  else
    cout<<"Yes"<<endl;
  
  return 0;
}