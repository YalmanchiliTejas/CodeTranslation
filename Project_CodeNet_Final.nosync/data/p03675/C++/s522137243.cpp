#include<bits/stdc++.h>

using namespace std;

typedef long long int lli ;

lli i,j,k,l,m,n,t,a,b,c,d,x,y,sum=0,total=0;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    //freopen("Input.txt","r",stdin);

    cin>>t;

    lli ar[t]={0},br[t]={0};

    for(i=0 ; i<t ; i++)
    {
        cin>>ar[i];
    }
    if(t>1)
    {
        if(t%2==0)  d=0;
        else    d=1;
        for(i=t-1 ; i>=0 ; i-=2)
        {
            cout<<ar[i]<<" ";
        }
        for(i=d ; i<t ; i+=2)
        {
            cout<<ar[i]<<" ";
        }
    }
    else
    {
        cout<<ar[0]<<" ";
    }
    cout<<endl;

}
