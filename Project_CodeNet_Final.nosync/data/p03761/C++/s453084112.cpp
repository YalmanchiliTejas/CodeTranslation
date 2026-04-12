#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int n,count;
    cin>>n;
    vector<string> s(n);
    string ans="";
    rep(i,n) cin>>s[i];
    for (char c='a'; c<='z'; c++) {
        int mini=100;
        rep(i,n) {
            count=0;
            rep(j,s[i].size()) {
                if (c==s[i][j]) count++;
            }
            mini=min(count,mini);
        }
        rep(i,mini) {
            ans.push_back(c);
        }
    }
    cout<<ans<<endl;
}
