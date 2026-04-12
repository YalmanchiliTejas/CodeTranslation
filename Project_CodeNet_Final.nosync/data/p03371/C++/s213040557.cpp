#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
#define  pi  pair<int,int>
#define  pb  push_back
#define  F   first
#define  S   second
const int N=2e5+2;
int a[4];
int main()
{
    ft
    int t,i,j,n,m,l,r,x,y,c=0;
    for(i=0; i<3; i++)
    {
        cin>>a[i];
    }
    cin>>x>>y;
    m=min(x,y);
    if((2*a[2])<=(a[0]+a[1]))
    {
        c+=2*m*a[2];
        l=abs(x-y);
        if(x>y)
        {
            if(a[0]>(2*a[2]))
            {
                c+=l*2*a[2];
            }
            else
            {
                c+=l*a[0];
            }
        }
        else
        {
            if(a[1]>(2*a[2]))
            {
                c+=l*2*a[2];
            }
            else
            {
                c+=l*a[1];
            }
        }
        cout<<c<<"\n";
    }
    else
    {
        c=(a[0]*x)+(a[1]*y);
        cout<<c<<"\n";
    }
    return 0;
}