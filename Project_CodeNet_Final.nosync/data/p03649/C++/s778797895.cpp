#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

const int INF=1001001001;
const int INFLL=1001001001001001001ll;
const int mod=1000000007;
inline void am(int &a,int b){
    a+=b;
    if(a>=mod)a-=mod;
}

int K;
int N;
int A[55];

signed main(){
    cin>>N;
    rep(i,N)cin>>A[i];

    int latte=accumulate(A,A+N,0ll);
    latte=max(0ll,latte-100000);

    int ans=latte;

    rep(i,N)A[i]+=latte;
    rep(i,N){
        int tmp=A[i]/(N+1);
        chmin(tmp,latte);
        A[i]-=tmp*(N+1);
        latte-=tmp;
    }
    assert(latte==0);

    while(true){
        int ma=max_element(A,A+N)-A;
        if(A[ma]<N){
            cout<<ans<<endl;
            return 0;
        }
        A[ma]-=N;
        rep(i,N)if(i!=ma)A[i]++;
        ans++;
    }


}
