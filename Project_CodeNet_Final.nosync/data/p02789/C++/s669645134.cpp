#include <bits/stdc++.h>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
ll gcd(ll a,ll b){
    if(a==0)
        return b;
    else
        return gcd(b%a,a);
}
ll findGCD(vector<ll> arr,ll n) 
{ 
    ll result = arr[0]; 
    for (ll i = 1; i < n; i++) 
        result = gcd(arr[i], result);
    return result; 
}

int main() {
    SPEED;
    cout.precision(8);
    cout << fixed;
    ll m,n;
    cin>>m>>n;
    if(m==n) cout<<"Yes";
    else cout<<"No";
    return 0;
}