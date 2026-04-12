#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    ll N,x,m;
    cin>>N>>x>>m;

    vector<int> ord(m,-1);
    vector<ll> rireki,syu;
    ll res=0;
    rep(n,N){
        if(ord[x]!=-1){
            int p=ord[x];
            for(int i=p;i<n;i++) syu.push_back(rireki[i]);
            break;
        }
        ord[x]=n;
        rireki.push_back(x);
        res+=x;
        x=(x*x)%m;
    }

    N-=rireki.size();
    if(N==0){
        cout<<res<<endl;
        return 0;
    }

    vector<ll> sum(syu.size()+1,0);
    rep(i,syu.size()) sum[i+1]=sum[i]+syu[i];

    ll q=N/syu.size();
    ll r=N%syu.size();
    res+=sum[syu.size()]*q+sum[r];
    cout<<res<<endl;
}