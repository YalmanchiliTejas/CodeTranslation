#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
using namespace std;
typedef long long ll;



int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<string> s(n);
    vector<vector<int>> vec(n,vector<int>(26,0));
    
    vector<char> ans;
    
    rep(i,n){
        cin >> s[i];
    }
    
    rep(i,n){
        rep(j,s[i].size()){
            vec[i][s[i][j]-'a']++;
        }
    }
    
    rep(i,26){
        int minv = 51;
        rep(j,n){
            minv = min(minv,vec[j][i]);
        }
        
        rep(k,minv){
            ans.push_back((i+'a'));
        }
    }
    
    sort(ans.begin(),ans.end());
    
    rep(i,ans.size()){
        cout << ans[i];
    }
}
