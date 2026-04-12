#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<int,int> P;
const LL mod=1000000007;
const LL LINF=1LL<<60;
const int INF=1<<30;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
 


int main(){
    int n;cin >> n;
    vector<LL> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    LL ans = 0;
    vector<vector<LL>> dp(n+1);
    for (int i = 1; i < n; i++) {
        dp[i].pb(0);
        set<int> st;
        bool f = false;
        for (int j = 1; j < (n-1)/i; j++) {
            if(f||n-1-i*j==i*j||st.find(n-1-i*j)!=st.end()||st.find(i*j)!=st.end()){
                dp[i].pb(0);
                f=true;
            }
            else{
                st.insert(i*j);
                st.insert(n-1-i*j);
                dp[i].pb(dp[i][j-1]+s[n-1-i*j]+s[i*j]);
            }
        }
    }
    for (int c = 1; c < n-1; c++) {
        for (int k = 1; k < (n-1)/c; k++) {
            ans = max(ans,dp[c][k]);
        }
    }
    cout << ans << endl;
    return 0;
}

