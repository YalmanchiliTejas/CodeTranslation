#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pint;

string s[51];
map<char,int> cnt,cnt2;
int main(){
    int n;
    cin>>n;
    rep(i,26){
        cnt2[(char)(i+'a')]=2555;
    }
    FOR(i,0,n){
        cin>>s[i];
        rep(i,26){
            cnt[(char)(i+'a')]=0;
        }
        rep(j,s[i].size()){
            ++cnt[s[i][j]];
        }
        for(auto it:cnt){
            cnt2[it.first]=min(cnt2[it.first],it.second);
        }
    }
    string ans;
    for(auto it:cnt2){
        if(it.second>0&&it.second!=2555){
            int c=it.second;
            while(c--) ans+=it.first;
        }
    }
    cout<<ans<<endl;
    return 0;
}