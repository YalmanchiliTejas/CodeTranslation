#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    a=a*100+b*10+c;
    if(a%4==0) cout<<"YES";
    else cout<<"NO";
    return 0;}