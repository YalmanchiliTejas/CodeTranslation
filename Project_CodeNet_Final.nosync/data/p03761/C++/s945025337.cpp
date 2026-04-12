#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pii pair<int,int>
const long long MOD=1e9+7;

int main(){
    int n;
    cin>>n;
    vector<int> abc(26,0);
    rep(i,n){
        string s;
        cin>>s;
        if(i==0){
            rep(j,s.size()) abc[(int)s[j]-'a']++;
        }
        else{
            vector<int> temp(26,0);
            rep(j,s.size()) temp[(int)s[j]-'a']++;
            rep(j,26)
                abc[j]=min(abc[j],temp[j]);
        }
        //rep(j,26) cout<<abc[j]<<" ";
        //cout<<endl;
    }
    
    rep(i,26) rep(j,abc[i]) cout<<char('a'+i);
    cout<<endl;
    return 0;
}
