#include<iostream>
using namespace std;
int main()
{
    int r,g,b,d;
    cin>>r>>g>>b;
    d=r*100+g*10+b;
    if(d%4==0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
