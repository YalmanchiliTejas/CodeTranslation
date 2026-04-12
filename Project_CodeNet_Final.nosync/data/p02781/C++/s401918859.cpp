#include <bits/stdc++.h>
using namespace std;

#define LL long int


int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;

    int sz = s.size();

    vector<int> num(sz);

    for(int i = 0; i < sz; ++i) num[i] = s[i] - '0';

    vector<vector<vector<LL> > > dp(sz + 1, vector<vector<LL> >(2, vector<LL>(k + 2, 0 ) ) );

    dp[0][0][0] = 1;

    for(int i = 0; i < sz; ++i){
        for(int smaller = 0; smaller < 2; ++smaller){
            for(int j = 0; j <= k; ++j){
                for(int x = 0; x <= (smaller ? 9 : num[i]); ++x){
                    dp[i + 1][smaller || x < num[i]][j + (x != 0)] += dp[i][smaller][j];
                }
            }
        }
    }

    cout << dp[sz][0][k] + dp[sz][1][k] << endl;

    return 0;
}