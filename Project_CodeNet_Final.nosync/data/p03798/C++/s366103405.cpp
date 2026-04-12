#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(),(a).end())
#define YN(a) if(a){cout<<"Yes"<<endl;}else cout<<"No"<<endl;//条件によってYes、Noを出力する
const int MOD=1000000007;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    s += s[0];
    bool ok=false;
    string ans;
    for(int j=0;j<4;j++){
        if(j==0) ans="SS";
        if(j==1) ans="SW";
        if(j==2) ans="WS";
        if(j==3) ans="WW";
        for(int i=1;i<=n;i++){
            if(s[i]=='o'&&ans[i]=='S'){
                ans += ans[i-1];
            }
            else if(s[i]=='o' && ans[i]=='W'){//嘘つき->左右が違う
                if(ans[i-1]=='W'){
                    ans += 'S';
                }
                else{
                    ans += 'W';
                }
            }
            else if(s[i]=='x' && ans[i]=='S'){
                if(ans[i-1]=='W'){
                    ans += 'S';
                }
                else{
                    ans += 'W';
                }
            }
            else{
                ans += ans[i-1];
            }
        }
        if(ans[0]==ans[n] && ans[1]==ans[n+1]) {
            ok = true;
            //cout<<ans<<endl;
            break;
        }
    }
    if(ok) {
        rep(i,n){
            cout<<ans[i];
        }
        cout<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}