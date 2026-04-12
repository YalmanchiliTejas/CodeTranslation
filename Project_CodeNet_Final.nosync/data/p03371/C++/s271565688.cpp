#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>vi;
vector<ll> :: iterator vt;
ll arr[200009];
int main()
{
    ll n,a,b,c,t,d,e,x,y,z,j,i,k,flag =0,maxi=LONG_LONG_MIN ,mini=LONG_LONG_MAX,sum=0;
    map<ll,ll>mp;
    map<ll,ll> :: iterator mt;
    string s, ss;
    cin>>a>>b>>c>>x>>y;
    ll sum1 =0 ;
    sum1 = a*x + b*y;
    mini = min(x,y);
    sum = c * mini *2;
    x-=mini;
    y-=mini;
    if(x == 0)
    {

        if(c*2>=b)
        sum+= y*b;
        else
            sum+=y*c*2;
    }
    else if(y == 0)
    {
        if(c*2>=a)
        sum+=x *a;
        else
            sum+=x*c*2;
    }
    cout<<min(sum,sum1)<<endl;
    return 0;
}
