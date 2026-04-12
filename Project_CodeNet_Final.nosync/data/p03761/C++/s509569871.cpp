#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
  int n;cin >>n;
  vector<vector<int>>cnt(n,vector<int>(26,0));
    for (int i = 0; i < n; ++i) {
        string s;cin >>s;
        int m=s.size();
        for (int j = 0; j < m; ++j) {
            cnt[i][s[j]-'a']++;
        }
    }
    vector<int>ans(26,INF);
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < n; ++j) {
            ans[i]=min(ans[i],cnt[j][i]);
        }
    }
    string res="";
    for (int k = 0; k <26; ++k) {
        for (int i = 0; i < ans[k]; ++i) {
            res+=(char)('a'+k);
        }
    }
    cout <<res<<endl;
}
