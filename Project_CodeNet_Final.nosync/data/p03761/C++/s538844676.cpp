#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef map<int,int> M;
typedef vector<int> V;
typedef queue<int> Q;
typedef pair<long,long> PLL;
typedef map<long,long> MLL;
typedef vector<long> VLL;
#define INF (int)(1e9)
#define MAXX 1.1529215e+18
#define inf 999999
#define EPS (1e-7)
#define MOD (1e9+7)
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define REP(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n-1);i>=0;i--)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);i++)
#define ALL(a)  a.begin(),a.end()
#define RALL(a) a.begin(),a.end(),greater<int>()
#define ROT(a) a.begin(),a.begin()+1,a.end()
#define RROT(a) a.begin(),a.end()-1,a.end()
#define PB push_back
#define MP make_pair
#define PI acos(-1.0)
/*--------------------------------------------*/

int main(){
    int n;cin>>n;
    vector<string>s(n);
    vector<int>ans(27);
    rep(i,n){
        cin>>s[i];
    }
    string first=s[0];
    rep(i,(int)first.size()){
        ans[first[i]-'a']++;
    }
    for(int i=1;i<n;i++){
        string now=s[i];
        vector<int>tmp(27);
        rep(j,(int)now.size()){
            tmp[now[j]-'a']++;
        }
        rep(k,27){
            if(tmp[k]){
                if(ans[k]>tmp[k]){
                    ans[k]=tmp[k];
                }
            }else{
                ans[k]=0;
            }
        }
    }
    rep(i,27){
        if(ans[i]){
            rep(j,ans[i]){
                printf("%c",'a'+i);
            }
        }
    }
    cout<<endl;
}
