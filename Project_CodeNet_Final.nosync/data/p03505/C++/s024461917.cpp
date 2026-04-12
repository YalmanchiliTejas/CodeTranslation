#include <bits/stdc++.h>
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;


int main() {
    ll k, a, b;
    cin >> k >> a >> b;
    if(a >= k)cout << 1 << endl;
    else{
        if(a <= b)cout << -1 << endl;
        else {
            cout << (k-a+a-b-1)/(a-b) * 2 + 1<< endl;
        }
    }
}   