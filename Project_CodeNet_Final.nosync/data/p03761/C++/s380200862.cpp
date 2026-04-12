#include<bits/stdc++.h>
#define ll long long
const ll MOD=1e9+7;
#define rep(i,l,r) for(int (i)=(l);(i)<(r);i++)
using namespace std;
int main(){
    int n;
    cin>>n;
    string ans="",s;
    vector<int> alp(26,100);
    rep(i,0,n){
        cin>>s;
        vector<int> buf(26,0);
        rep(j,0,(int)s.length()){
            buf[s[j]-'a']++;
        }
        rep(j,0,26)alp[j]=min(alp[j],buf[j]);
    }
    rep(i,0,26){
        for(int j=alp[i];j>0;j--)ans+='a'+i;
    }
    cout<<ans<<endl;
}