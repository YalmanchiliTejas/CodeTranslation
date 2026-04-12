#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;
#define rep(i,a) for(ll i=0;i<a;++i)
int main(){
    string s; cin >> s;
    ll k; cin >> k;
 
    ll sz = s.size();
    vector<int>num(sz);
 
    rep(i,sz) num[i] = s[i] - '0';
    ll dp[1000][2][k+100]; 
    dp[0][0][0] = 1;
 
    rep(i,sz)rep(smaller,2)rep(j,4)
            for(int x = 0; x <= (smaller ? 9 : num[i]); ++x)// if smaller ==1 update 0~9, else update 0~num[i]
                dp[i + 1][smaller || x < num[i]][j + (x != 0)] += dp[i][smaller][j];// if x==0(位數j不變0), else +1
                // if smaller ==0 && (x>num[i]||x==0) update 0
    cout << dp[sz][0][k] + dp[sz][1][k] << endl;
 
    return 0;
}