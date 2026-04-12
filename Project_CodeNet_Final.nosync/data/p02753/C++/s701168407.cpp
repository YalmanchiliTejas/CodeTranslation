#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long  int a,t,i,j=0,c,n=0,sum=0,x,y,b,p,m=0,q=0;

    string s;
    cin>>s;
    for(i=0; i<3; i++)
    {
        if(s[i]=='A')
        {
            m++;

        }
        else
        {
            n++;

        }
    }
    if(m>0 && n>0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;


    return 0;

}
