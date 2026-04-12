#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector <char>v,v1,v2;
    int a,b,i,j,t,sum,n,cunt1=0,cunt2=0,cunt=0,tem=0,k;
    string s;
    cin>>s;
    for(i=0;i<s.size();i++)
    {
        if(s[i]=='A')
            cunt1=1;
        else cunt2=1;

    }
    if(cunt1==1&&cunt2==1)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}
