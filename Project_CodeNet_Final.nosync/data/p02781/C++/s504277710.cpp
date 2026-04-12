#include <bits/stdc++.h>
using namespace std;
//using Graph = vector<vector<int>>;
#define rep(i, b) for (int i = 0; i < (b); i++ )

typedef pair<int,int> P;
typedef long long ll;

const int INF = 100000000;
const double PI=acos(-1);

bool comp(P p1, P p2){
    if (p1.first != p2.first) {
        return p1.first < p2.first;
    }
    else if (p1.second != p2.second) {
        return p1.second > p2.second;
    }
    else {
        return true;
    }
}

int dp[150][2][2][6];

int main () {
    string N;
    int K;
    cin >> N >> K;
    vector<int> X(0);
    rep(i,N.size()) {
        X.push_back(N[i]-'0');
    }

    dp[0][0][0][0] = 1;

    for (int i=0; i<X.size(); i++) {
        for (int smaller=0; smaller<2; smaller++) {
            for (int m = 0; m<2 ; m++) {
                for (int k = 0; k<=K; k++) {
                    for (int x = 0; x<= (smaller ? 9 : X[i]); x++) {
                        if (m==0) {
                            dp[i+1][smaller || x < X[i]][m || x!=0][k+(x!=0)] += dp[i][smaller][m][k];
                        }
                        else {
                            dp[i+1][smaller || x < X[i]][m][k+(x!=0)] += dp[i][smaller][m][k];
                        }
                    }
                }
            }
        }
    }
	
    ll ans = dp[X.size()][0][0][K] + dp[X.size()][1][0][K] +dp[X.size()][0][1][K] + dp[X.size()][1][1][K];
    cout << ans << endl;

}
