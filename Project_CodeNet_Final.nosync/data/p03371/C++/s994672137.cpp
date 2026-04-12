#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define PI 3.1415926535897932384626
#define boost ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define MOD 1000000007
#define forn(i,n) for(int i=0;i<n;i++)
int main()
{
       boost;
       ll a,b,c,x,y,cost=0;
       cin>>a>>b>>c>>x>>y;
       while(x && y)
       {
             ll p=a+b;
             ll q=2*c;
             cost+=min(p,q);
             x--;
             y--;
       }
       if(x || y)
       {
             if(x)
             {
                   while(x)
                   {
                         cost+=min(a,2*c);
                         x--;
                   }
             }
             if(y)
             {
                   while(y)
                   {
                         cost+=min(b,2*c);
                         y--;
                   }
             }
       }
       cout<<cost<<endl;
}     
