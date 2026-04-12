#include<iostream>
using namespace std;
int t1,t2;
string s;
int main()
{
    int i;
    cin>>s;
    for(i=0;i<3;i++) 
    {
        if(s[i]=='A') t1=1;
        else t2=1;
    }
    if(t1==1&&t2==1) cout<<"Yes";
    else cout<<"No";
}

    
