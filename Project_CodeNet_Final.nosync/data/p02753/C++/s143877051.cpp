#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;


int main(){

    string s;
    cin>>s;
    int cnt[2]={};
    rep(i,3){
        cnt[s[i]-'A']++;
    }
    string ans="Yes";
    rep(i,2)if(!cnt[i])ans="No";

    cout<<ans<<endl;

    return 0;

}
/*


*/
