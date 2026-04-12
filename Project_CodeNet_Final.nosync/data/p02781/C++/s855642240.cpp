#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll mod = 1000000007;
const int INF = 1001001001;

int main(){
    string s; cin >> s;
    ll n = s.size();
    int k; cin >> k;
    vector<vector<pair<ll,ll>>> dp(n+2,vector<pair<ll,ll>>(103,make_pair(0,0)));
    dp.at(1).at(0) = make_pair(1,0);
    dp.at(1).at(1) = make_pair((ll)(s.at(0) - '1'),1);
    for(int i=1;i<n;i++){
        for(int j=0;j<=i;j++){
            dp.at(i+1).at(j).first += dp.at(i).at(j).first;
            dp.at(i+1).at(j+1).first += dp.at(i).at(j).first * 9;
            if(dp.at(i).at(j).second == 1){
                if(s.at(i) == '0'){
                    dp.at(i+1).at(j).second = 1;
                }else{
                    dp.at(i+1).at(j).first++;
                    dp.at(i+1).at(j+1).first += (ll)(s.at(i) - '1');
                    dp.at(i+1).at(j+1).second = 1;
                }
            }
        }
    }
    /*
    rep(i,n+1){
        rep(j,10){
            cout << dp.at(i).at(j).first << dp.at(i).at(j).second << " ";
        }
        cout << endl;
    }
    */
    cout << dp.at(n).at(k).first + dp.at(n).at(k).second << endl;
}