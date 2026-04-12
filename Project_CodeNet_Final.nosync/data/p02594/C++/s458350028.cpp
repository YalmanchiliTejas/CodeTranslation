#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define bg begin()
#define en end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
ll gcd(ll a,ll b){
    if(a==0)
    return b;
    else
    return gcd(b%a,a);
}
ll sod(ll x){
    ll r,sum=0;
    while(x>0){
        r=x%10;
        x/=10;
        sum+=r;
    }
    return sum;
}
using namespace std;
int main()
{
    ll n;
    cin>>n;
    if(n>=30)
    cout<<"Yes";
    else
    cout<<"No";
    
}