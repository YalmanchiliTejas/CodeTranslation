#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll =  long long ;
using P = pair<int,int> ;
const ll INF = 1e14;
const int MOD = 1000000007;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool ok = false;
    vector<int> ans(n);
    rep(fi,2)rep(se,2){
        if(ok) break;
        ans[0] = fi,ans[1] = se;
        for(int i=2;i<n;i++){
            ans[i] = abs(ans[i-2]-((s[i-1]=='o') ^ (ans[i-1]==0)));
        }
        if(((s[0]=='o') ^ (ans[0]==0)) - abs(ans[1]-ans[n-1]) == 0){
            if(((s[n-1]=='o') ^ (ans[n-1]==0)) - abs(ans[0]-ans[n-2]) == 0){
                ok = true;
            }
        }
    }
    if(ok){
        rep(i,n) cout << (ans[i]==0 ? 'S' : 'W') ;
        cout << endl;
    }else{
        cout << -1 << endl;
    }

    return 0;
}