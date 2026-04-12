#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )

 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    int N;
    cin >> N;
    vector<vector<int>> A(26,vector<int>(N,0));

    rep(i,N) {
        string S;
        cin >> S;
        rep(j,S.size()) {
            int idx = S[j] - 'a';
            A[idx][i]++;
        }
    }
    
    vector<int> B(26,0);
    string ans = "";
    rep(i,26) {
        int n = INF;
        rep(j,N) {
            n = min(n,A[i][j]);
        }
        rep(j,n) {
            char tmp = 'a' + i;
            ans += tmp;
        }
    }
    cout << ans << endl;

}
