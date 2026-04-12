#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define mod 1000000007
#define f(i,a,b) for(ll i=a;i<b;i++)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ii pair<ll,ll>
#define vii vector<ii>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define MAX 1e9
 
ll modpow(ll base, ll exp, ll modulus) {base %= modulus;ll result = 1;while (exp > 0) {if (exp & 1) result = (result * base) % modulus;base = (base * base) % modulus;exp >>= 1;}return result;}
const ld pi=acos(-1);

int main(){
    IOS;
    ll n,m;cin>>n>>m;
    if(n==m)cout<<"Yes";
    else cout<<"No";
    return 0;  
} 