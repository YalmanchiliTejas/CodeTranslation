#include "bits/stdc++.h"
using namespace std;
#define test int t; cin >> t; while (t--)
#define fast ios::sync_with_stdio(NULL); cin.tie(NULL)
#define mod 1073741824
#define endl "\n"
#define gcd(m,n) __gcd(m,n)
#define lcm(m,n) m*(n/gcd(m,n))
#define all(v) v.begin(),v.end()
#define ll long long
#define file freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define pb push_back
#define time 1.0 * clock() / CLOCKS_PER_SEC
ll MAX=10e10;

int main(){
    fast;
    int x;
    cin>>x;
    if(x>=30)
        cout<<"Yes";
    else
        cout<<"No";

    return 0;
}