#include <iostream>
#include <cstdlib>
#include <fstream>
#include <set>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <numeric>

using namespace std;

typedef long long ll;

#define forn(i, n) for(int i = 0; i < (int)(n);++i)
#define fore(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)
#define fi first
#define se second
#define pb push_back
#define pll pair<ll,ll>
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi>
#define vpll vector<pll>
#define vll vector<ll>
#define vvll vector<vll>
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()


void fastik() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

//ifstream &cin
void solve(){

}


int main() {
    fastik();
    ll n;cin>>n;
    vll a(n);
    forn(i,n){
        cin >> a[i];
    }
    ll ans = 1;
    fore(i,1,n-1){
        ll f = 1;
        forn(j,i){
            if(a[j] > a[i]){
                f = 0;
            }
        }
        if(f==1){
            ans++;
        }
    }
    cout << ans;
}