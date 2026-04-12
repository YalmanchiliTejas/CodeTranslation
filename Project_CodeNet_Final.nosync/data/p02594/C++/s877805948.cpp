/*
    Created by Tejas Chaudhari
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef double lf;
typedef bool bl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<lf> vd;
typedef vector<bl> vb;
typedef string st;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;

#define INF (LONG_LONG_MAX / 4)
#define Mod % 1000000007
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

void re_curse() {
    ll x;
    cin>>x;
    if (x >= 30) {
        cout<<"Yes"<<endl;
    } else {
        cout<<"No"<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin>>t;
    for (int i = 1; i <= t; ++i) {
        re_curse();
    }
    return 0;
}
