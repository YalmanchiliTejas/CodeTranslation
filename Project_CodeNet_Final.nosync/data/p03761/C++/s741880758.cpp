#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
#include <bits/stdc++.h>
#include <numeric>
using namespace std;
typedef long long ll;
const int mod= 1e+9+7;

int main() {
    int n;cin>>n;
    vector<string>s(n);
    vector<int>l(n);
    rep(i,n){
        cin>>s[i];
        l[i]=s[i].size();
    }
    int cnt;
    int mn;
    string ans;
    for(char c='a';c<='z';c++){
        mn=10100;
        rep(i,n){
            cnt=0;
            rep(j,l[i]){
                if(s[i][j]==c){
                    cnt++;
                }
            }
            mn =min(cnt,mn);
        }
            rep(i,mn){
            ans+=c;
        }
    }
    sort(ans.begin(),ans.end());
    cout<<ans<<endl;
}