#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int INF = 2e9;

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vector<int> cnt(26,INF);
    rep(i,n){
        vector<int> re(26,0);
        string a = s[i];
        rep(j,a.size()){
            int num = a[j];
            re[num-97]++;
        }
        rep(i,26){
            cnt[i] = min(cnt[i],re[i]);
        }
    }
    rep(i,26){
        if(cnt[i] == INF)continue;
        else{
            char ans = i + 97;
            rep(j,cnt[i]) cout << ans;
        }
    }
    cout << endl;
}