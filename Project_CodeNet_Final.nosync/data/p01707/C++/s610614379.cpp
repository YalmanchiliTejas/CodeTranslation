#include <bits/stdc++.h>

using namespace std;

using ll=long long int;

template<typename T>
constexpr T modpow(T a,T n,T mod){
    T ret=1;
    while(n>0){
        if((n&1)!=0){
            ret=ret*a%mod;
        }
        a=a*a%mod;
        n=n/2;
    }
    return ret;
}

template <typename T>
struct LazySegmeTree{
private:
    int n;
    T init;
    vector<T> node;
    vector<T> lazy;
    void update(int k){
        if(lazy[k]!=0){
            node[k]+=lazy[k];
            if(k<n-1){
                lazy[2*k+1]+=lazy[k]/2;
                lazy[2*k+2]+=lazy[k]/2;
            }
            lazy[k]=0;
        }
    }
public:
    explicit LazySegmeTree(int sz,T initv=0){
        n=1;
        init=initv;
        while(n<sz)n=n*2;
        node.resize(static_cast<unsigned int>(2*n-1),init);
        for (int i = 0; i < sz; ++i) {
            node[i+n-1]=init;
        }
        for (int i = n-2; i >= 0; --i) {
            node[i]=node[2*i+1]+node[2*i+2];
        }
        lazy.resize(static_cast<unsigned int>(2*n-1),init);
        for (int i = 0; i < sz; ++i) {
            lazy[i+n-1]=init;
        }
        for (int i = n-2; i >= 0; --i) {
            lazy[i]=lazy[2*i+1]+lazy[2*i+2];
        }
    }

    void add(int p,int q,T val,int k=0,int l=0,int r=-1){
        if(r<0)r=n;
        update(k);
        if(r<=p||l>=q)return;
        if(p<=l&&r<=q){
            lazy[k]+=val*(r-l);
            update(k);
        }
        else{
            add(p,q,val,2*k+1,l,(l+r)/2);
            add(p,q,val,2*k+2,(l+r)/2,r);
            node[k]=node[2*k+1]+node[2*k+2];
        }
    }

    T getsum(int p,int q,int k=0,int l=0,int r=-1){
        if(r<0)r=n;
        if(r<=p||l>=q)return 0;

        update(k);
        if(p<=l&&r<=q)node[k];
        T vl=getsum(p,q,2*k+1,l,(l+r)/2);
        T vr=getsum(p,q,2*k+2,(l+r)/2,r);
        return vl+vr;
    }


};

bool solve(){
    ll n,d,x;
    ll mod=1000000007;
    cin>>n>>d>>x;
    if(n==0)return false;

    //vector<LazySegmeTree<ll>> dp(n+1,LazySegmeTree<ll>(n+1,0ll));
    vector<vector<ll> > dp(n+1,vector<ll>(n+1,0ll) );
    dp[0][n] = 1;

    for (int i = 1; i < n+1; ++i) {
        for (int j = 1; j < n+1; ++j) {
            int l=max(0ll,j-x+1);
            //dp[i].add(l,j,dp[i-1].getsum(j,j+1));
	    dp[i][l] += dp[i-1][j];
	    dp[i][l] %= mod;
	    dp[i][j] -= dp[i-1][j];
	    dp[i][j] += mod;
	    dp[i][j] %= mod;
        }

	for(int j=0;j<n;j++){
	    dp[i][j+1]+=dp[i][j];
	    dp[i][j+1]%=mod;
	}

    }

    ll sum=0;

    for (ll i = 0; i <n+1; ++i) {
        ll dck=1;
        for (ll j = 0; j < i ; ++j) {
            dck*=(d-j)%mod;
            dck%=mod;
            dck*=modpow(j+1,mod-2,mod);
	    //cout<<"mo"<<modpow(j+1,mod-2,mod)<<endl;
            dck%=mod;
        }
	//cout<<' '<<dck<<endl;
	//dck += mod;
	//dck %= mod;
	//cout<<"days"<<i<<' '<<dck<<' '<<dp[i][0]<<' '<<(dp[i][0]*dck)%mod<<endl;
        sum+= (dp[i][0]*dck)%mod;
        sum%=mod;
    }
    cout<<sum<<endl;
   // cout<<"mod#"<< (3*modpow(3ll,mod-2,mod) )%mod<<endl;
    return true;
}

int main(){
    while(solve());
    return 0;
}
