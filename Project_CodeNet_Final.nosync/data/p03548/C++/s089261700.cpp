#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c;
    a-=2*c;
    d=a%(b+c);
    a=a/(b+c);
    if(d==b)a++;
    cout<<a<<endl;
}