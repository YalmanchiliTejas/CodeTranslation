#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int n;
    cin>>n;
    vector<string>s(n);
    vector<int>ans(26,51);
    rep(i,n){
        cin>>s[i];
        vector<int>x(26,0);
        rep(j,s[i].size()){
            x[s[i][j]-'a']++;
        }
        rep(j,26){
            ans[j]=min(x[j],ans[j]);
        }
    }
    rep(i,26){
        rep(j,ans[i]){
            if(ans[i]==51)continue;
            cout<<char(i+'a');
        }
    }
    cout<<endl;
    return 0;
}
