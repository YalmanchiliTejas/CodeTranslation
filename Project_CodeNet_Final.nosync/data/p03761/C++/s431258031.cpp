#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7  
using ll = long long; 
using P=pair<int,int>;
using lP=pair<ll,ll>;
using fP=pair<double,double>;
ll const mod=998244353;
const ll MAX=300000;
using vi=vector<int>;
using vc=vector<char>;
using vs=vector<string>;
using vvi =vector<vector<int>>;
using vvc=vector<vector<char>>;
using vvp =vector<vector<P>>;
int main(){
    int n;
    cin>>n;
    vvi c(n,vi(26));
    rep(i,n){
        string s;
        cin>>s;
        rep(j,s.size()){
            c[i][s[j]-'a']++;
        }
    }
    vc ans;
    rep(i,26){
        bool ok=true;
        int cnt=INF;
        rep(j,n){
            if(c[j][i]==0){
                ok=false;
                break;
            }
            else cnt=min(cnt,c[j][i]);
        }
        if(ok){
            rep(j,cnt)ans.push_back((char)(i+'a'));
        }
    }
    rep(i,ans.size())cout<<ans[i];
    cout<<endl;
    return 0;
}