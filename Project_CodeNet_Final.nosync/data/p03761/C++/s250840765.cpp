//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    int n; cin>>n;
    vector<int> c(26,inf);
    rep(i,n){
        string s; cin>>s;
        vector<int> cnt(26,0);
        for(auto ch:s) cnt[ch-'a']++;
        rep(j,26) c[j]=min(c[j],cnt[j]);
    }
    rep(i,26)rep(j,c[i]){
        cout<<(char)('a'+i);
    }
    cout<<endl;
}