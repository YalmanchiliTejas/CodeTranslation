/* Trico */
#include <iostream>
#include <bits/stdc++.h>
#define inf 1e18
#define ll long long
#define x first
#define y second
#define pll pair<ll, ll>
#define pii pair<int, int>
#define mll map<ll, ll>
#define mii map<int, int>
#define vll vector<ll>
#define vi vector<int>
#define pb push_back
#define p push
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, x, curr = 0, ans = 1;
    cin>>n;
    cin>>curr;
    for(int i = 1;i<n;i++){
        cin>>x;
        if(x >= curr) ans++;
        curr = max(x, curr);
    }
    cout<<ans;
} 