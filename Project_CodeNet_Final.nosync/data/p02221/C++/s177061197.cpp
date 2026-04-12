#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using P = pair<int, int>;
using P3 = pair<double,P>;
using PP = pair<P, P>;
constexpr int INF = 1 << 30;
constexpr ull MOD = 998244353;
constexpr int di[] = {0, 1, 0, -1};
constexpr int dj[] = {1, 0, -1, 0};
constexpr double EPS = 1e-9;

int N;
string s;

auto f = [](int x, int y){
    if(x > y) swap(x, y);
    if(x == -1) return y;
    if(s[y-x-1] == '0') return x;
    else return y;
};

int main(){
    cin >> N >> s;
    vector<int> p(1<<(N+1));
    for(int i=0;i<(1<<N);i++){
        cin >> p[i];
        p[i+(1<<N)] = p[i];
    }
    vector<vector<int> > dp(N+1, vector<int>(1<<(N+1),-1));  // dp[k][i] 人iから数えて2**k人のトーナメントの勝者
    for(int i=0;i<(1<<(N+1));i++){
        dp[0][i] = p[i];
    }
    for(int k=0;k<N;k++){
        for(int i=0;i<(1<<(N+1))-(1<<k);i++){
            dp[k+1][i] = f(dp[k][i],dp[k][i+(1<<k)]);
        }
    }
    for(int i=0;i<(1<<N);i++){
        cout << dp[N][i] << endl;
    }
    return 0;
}
