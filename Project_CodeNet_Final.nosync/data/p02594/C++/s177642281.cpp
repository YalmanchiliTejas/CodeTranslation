//tanzim bin nasir
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<ll,ll>
#define ff first
#define ss second
using namespace std;
void fast()
{
ios::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
}
ll gcd(ll a,ll b)
{
    if(b==0)
    return a;
    else
    gcd(b,a%b);
}
ll lcd(ll a,ll b)
{
    return (a*b)/gcd(a,b);
}
int main()
{
    ll n;
    cin>>n;
    if(n>=30)
    cout<<"Yes\n";
    else
    cout<<"No\n";
}