#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=0; i<n; i++)
template <class T> ostream& operator<<(ostream& os, const vector<T>& v){ os << "{"; for(size_t i=0; i<v.size(); i++) os << v[i] << (i+1==v.size() ? "" : ", "); os << "}"; return os; }
template <class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p){ return os << "{" << p.first << ", " << p.second << "}"; }

long long dp[3003][3003];
bool vis[3003][3003];
vector<long long> a;

long long func(int x, int y, int turn){
    if(x > y) return 0;
    if(vis[x][y]) return dp[x][y];
    vis[x][y] = true;
    if(turn == 0){
        long long s0 = a[x] + func(x+1, y, 1);
        long long s1 = a[y] + func(x, y-1, 1);
        if(s0 > s1){
            dp[x][y] = s0;
            return dp[x][y];
        }else{
            dp[x][y] = s1;
            return dp[x][y];
        }
    }else{
        long long s0 = -a[x] + func(x+1, y, 0);
        long long s1 = -a[y] + func(x, y-1, 0);
        if(s0 < s1){
            dp[x][y] = s0;
            return dp[x][y];
        }else{
            dp[x][y] = s1;
            return dp[x][y];
        }
    }
}

int main(){
    int N;
    cin >> N;
    a.resize(N);
    REP(i, N) cin >> a[i];
    cout << func(0, N-1, 0) << endl;
    return 0;
}