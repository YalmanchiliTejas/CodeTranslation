#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll ans=0;
int n;
int i;
int main()
{
    int flag=0,f2=0;
    char op;
    for(i=0;i<3;i++)
    {
        cin>>op;
        if(op=='A')
            flag=1;
        if(op=='B')
            f2=1;
    }
    if(f2==1&&flag==1)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}

