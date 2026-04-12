#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int llu;
typedef long double ld;
#define vi vector<int>
#define vl vector<ll>
#define vp vector<pair<int,int>>
#define pb push_back
#define pf push_front
#define mp map<ll,ll>
#define INF 1000000000000000000
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
ll gcd(ll a,ll b)
{
    if(a==0)
    {
        return b;
    }
    else
    {
        return gcd(b%a,a);   
    }
}
ll lcm(ll a,ll b)
{
    return a*b/gcd(a,b);
}
int f(char c)
{
    return (int)c-96;
}
/**********************************************************************
***********************************************************************
*********************ACTUAL CODE BEGINS HERE***************************/
int main()
{   
    fast;
    int x;
    cin>>x;
    if(x>=30)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;   
    }
    return 0;
}