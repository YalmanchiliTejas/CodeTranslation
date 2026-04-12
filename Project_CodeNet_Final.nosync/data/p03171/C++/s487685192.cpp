#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

const int MAXN = 3005;
vector< vector <vector<P>> > dp (MAXN, vector<vector<P>>(MAXN, vector<P>(2)) );
vector<int> a(MAXN);
bool visited[MAXN][MAXN][2];

P q(int i, int j, int k) { //k=1太郎, a_i...a_jでkが操作
    if (visited[i][j][k]) return dp[i][j][k];
    else if (i > j) return P (0,0);
    P front, back;
    if (k == 0) { //太郎
        front = q(i+1, j, k+1);
        front.first += a[i];
        back = q(i, j-1, k+1);
        back.first += a[j];
        if (front.first-front.second >= back.first-back.second) dp[i][j][k] = front;
        else dp[i][j][k] = back;
    }
    else if (k == 1) {                
        front = q(i+1, j, k-1);
        front.second += a[i];
        back = q(i, j-1, k-1);
        back.second += a[j];
        if (front.first-front.second <= back.first-back.second) dp[i][j][k] = front;
        else dp[i][j][k] = back;
    }
    visited[i][j][k] = true;
    return dp[i][j][k];
}

int main() {
    int N;
    cin >> N;
    rep(i,N) cin >> a[i];
    P result = q(0, N-1, 0);
    cout << (result.first-result.second) << endl;
    return 0;
}