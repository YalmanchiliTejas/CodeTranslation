#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define int long long
#define double long double
#define mod 1000000007
#define F first
#define S second
#define P pair<long long,long long>
#define all(a) a.begin(),a.end()
#define INF 10000000000000000
#define endl '\n'
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

//power_mod
inline int Pow_mod(int x, int pow){
    if(pow==0) return 1;
    int a=Pow_mod(x, pow/2);
    a=a*a%mod;
    if(pow%2==1) a*=x;
    return a%mod;
}

//factorial_mod
int* fact_mod;
inline void init_fact_mod(int x){
    fact_mod = new int[x];
    fact_mod[0]=1;
    rep(i,x-1)fact_mod[i+1]=fact_mod[i]*(i+1)%mod;
}

//permutation_mod
inline int nPr_mod(int n, int r){
    return fact_mod[n]*Pow_mod(fact_mod[n-r]%mod, mod-2)%mod;
}

//combination_mod
inline int nCr_mod(int n, int r){
    return fact_mod[n]*Pow_mod(fact_mod[n-r]*fact_mod[r]%mod, mod-2)%mod;
}

//abc127
signed main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,m,k; cin>>n>>m>>k;
    vector<vector<int>> grid(n*2,vector<int>(m*2,0));

    rep(i,n*2-1)rep(j,m*2-1){
        grid.at(i+1).at(j+1)=abs(n-1-i)+abs(m-1-j);
    }

    rep(i,n*2-1)rep(j,m*2-1){
        grid.at(i+1).at(j+1)=grid.at(i+1).at(j+1)+grid.at(i).at(j+1)+grid.at(i+1).at(j)-grid.at(i).at(j);
    }

    int ans=0;
    init_fact_mod(200100);
    rep(i,n)rep(j,m){
        int tmp=grid.at(n+i).at(m+j)-grid.at(i).at(m+j)-grid.at(n+i).at(j)+grid.at(i).at(j);
        tmp%=mod;
        //ans=(ans+(nCr_mod(n*m-1,k-1)*n%mod*m%mod)*tmp%mod)%mod;
        int tmp2=nCr_mod(n*m-1,k-1)*(k-1)%mod*Pow_mod(n*m-1,mod-2)%mod;
        ans=(ans+tmp*tmp2%mod)%mod;
    }
    cout<<ans*Pow_mod(2,mod-2)%mod<<endl;

}