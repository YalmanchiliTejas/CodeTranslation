#include<cstdio>
#include<iostream>
using namespace std;
int a,b,c,tot;
int main()
    {
        cin>>a>>b>>c;
        tot=100*a+10*b+c;
        if(tot%4) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        return 0;
    }