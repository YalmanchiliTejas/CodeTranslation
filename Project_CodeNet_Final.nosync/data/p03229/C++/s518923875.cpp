#include <iostream>
#include "bits/stdc++.h"
using namespace std;
#define print(x) cout<<x<<endl;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a) for(int i=0;i<a;i++)
#define debug int debug = 0;
#define RREP(i,a) for(int i=a-1;i>=0;i--)
#define rrep(i,a,b) for(int i=a-1;i>=b;i--)
#define printall(n,array) {for(int i=0;i<n;i++){cout<<array[i]<<" ";}cout<<endl;}
#define U() cout<<endl;
typedef long long ll;
typedef pair<int, int> Pi;
typedef pair<int, Pi> V;
typedef vector<ll> VE;
const ll mod = 1e9 + 7; //10^9+7

int main(){
    int n;
    VE a, small, big;
    cin >> n;
    ll A;
    REP(i, n){
        cin >> A;
        a.push_back(A);
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    if(n % 2 == 0){
        REP(i, n){
            if(i < n / 2){
                small.push_back(a[i]);
            }else{
                big.push_back(a[i]);
            }
        }
        sort(big.rbegin(), big.rend());
        REP(i, big.size() - 1){
            ans += 2 * big[i];
        }
        REP(i, small.size() - 1){
            ans -= 2 * small[i];
        }
        ans = ans + big[big.size() - 1] - small[small.size() - 1];
    }else{
        REP(i, n){
            if(i < n / 2){
                small.push_back(a[i]);
            }else{
                big.push_back(a[i]);
            }
        }
        sort(big.rbegin(), big.rend());
        REP(i, big.size() - 2){
            ans += 2 * big[i];
        }
        ans += big[big.size() - 2] + big[big.size() - 1];
        REP(i, small.size()){
            ans -= 2 * small[i];
        }

        small = {};
        big = {};
        ll tmp = 0;
        REP(i, n){
            if(i < n / 2 + 1){
                small.push_back(a[i]);
            }else{
                big.push_back(a[i]);
            }
        }
        sort(big.rbegin(), big.rend());
        REP(i, big.size()){
            tmp += 2 * big[i];
        }
        REP(i, small.size() - 2){
            tmp -= 2 * small[i];
        }
        tmp = tmp - small[small.size() - 2] - small[small.size() - 1];
        ans = max(ans, tmp);
    }


    print(ans);
}
