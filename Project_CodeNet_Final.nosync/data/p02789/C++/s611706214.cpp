#include <bits/stdc++.h>
using namespace std;
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define endl '\n'
#define vi vector<ll>
#define vb vector<bool>
#define mii map<ll, ll>
#define pii pair<ll, ll>
#define pb push_back
#define fi first
#define se second
//just see queue data structure, solve it like 600 rating problem.
ll power(ll a, ll b){
    ll res = 1;
    while(b!=0){
        if(b&1){
            res *= a; 
        }
        a = (a * a);
        b = (b / 2);
    }
    return res;
}
int main(){
    SPEED;
    ll n, m;
    cin>>n>>m;
    if(n==m){
        cout<<"Yes";
    }
    else cout<<"No";
    return 0;
}