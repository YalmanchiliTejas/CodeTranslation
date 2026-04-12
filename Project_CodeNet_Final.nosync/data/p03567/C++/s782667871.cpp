#include<iostream>
#include<string>
using namespace std;
int main()
{
    string x;
    cin>>x;
    for(int i=0;i<x.length();i++)
        if(x[i]=='A'&&x[i+1]=='C'){cout<<"Yes"<<endl;return 0;}
    cout<<"No"<<endl;
    return 0;
}
