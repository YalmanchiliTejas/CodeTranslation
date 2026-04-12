#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define a first
#define b second
#define sz(x) (ll)((x).size())
#define pf push_front
#define pb push_back
#define mp make_pair 
#define bg begin()
#define ed end()
#define all(x) (x).bg,(x).ed
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep1(i,n) for(ll i=1;i<=(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
const ll MOD=1000000007;
const ll INF=1000000000000000;

template<class T> inline bool chmin(T& a, T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a=b;return true;}return false;}

int main(){
	//input
	ll N; cin>>N;

    if(N==1){
        cout<<0;
        return 0;
    }

	vector<ll> A(N+1);
    A[0]=-INF;
    vector<ll> B(N+1);
    B[0]=-INF;

    rep1(i,N){
        cin>>A[i];
        B[i]=-A[i];
    }
    sort(all(A));
    sort(all(B));

    ll ans;
    if(N%2==1){
        ll tmpA=0,tmpB=0;
        rep1(i,(N-1)/2){
            tmpA-=2*A[i];
            tmpB-=2*B[i];
        }
        FOR(i,(N+1)/2,(N+5)/2){
            tmpA+=A[i];
            tmpB+=B[i];
        }
        FOR(i,(N+5)/2,N+1){
            tmpA+=2*A[i];
            tmpB+=2*B[i];
        }
        ans=max(tmpA,tmpB);
    }
    else{
        ll tmpA=0,tmpB=0;
        rep1(i,(N-2)/2){
            tmpA-=2*A[i];
            tmpB-=2*B[i];
        }
        tmpA-=A[N/2];
        tmpB-=B[N/2];
        tmpA+=A[N/2+1];
        tmpB+=B[N/2+1];
        FOR(i,N/2+2,N+1){
            tmpA+=2*A[i];
            tmpB+=2*B[i];
        }
        ans=max(tmpA,tmpB);
    }

    cout<<ans;
}