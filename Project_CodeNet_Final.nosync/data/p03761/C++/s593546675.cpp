#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {

    ll n;
    cin >> n;
    string S[n];
    rep(i,n) cin >> S[i];
    string out = "";
    ll N = S[0].length();
    rep(i,N){
        ll cnt = 0;
        for(ll j=1;j<n;j++){
            ll M = S[j].length();
            rep(k,M){
                if(S[j][k]==S[0][i]){
                    S[j].erase(k,1);
                    cnt++;
                    break;
                }
            }
        }
        if(cnt==n-1) out += S[0][i];
    }
    sort(out.begin(),out.end());
    cout << out << endl;
    return 0;
}
