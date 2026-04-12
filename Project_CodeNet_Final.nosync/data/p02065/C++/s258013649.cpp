#include<iomanip>
#include<limits>
#include<thread>
#include<utility>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<numeric>
#include<cassert>
#include<random>
#include<chrono>
#include<unordered_set>
#include<unordered_map>
#include<fstream>
#include<list>
#include<functional>
#include<bitset>
#include<complex>
#include<tuple>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef long double D;
typedef complex<D> P;
#define F first
#define S second
const ll E=1e18+7;
const ll MOD=1000000007;

template<typename T,typename U>istream & operator >> (istream &i,pair<T,U> &A){i>>A.F>>A.S; return i;}
template<typename T>istream & operator >> (istream &i,vector<T> &A){for(auto &I:A){i>>I;} return i;}
template<typename T,typename U>ostream & operator << (ostream &o,const pair<T,U> &A){o<<A.F<<" "<<A.S; return o;}
template<typename T>ostream & operator << (ostream &o,const vector<T> &A){ll i=A.size(); for(auto &I:A){o<<I<<(--i?" ":"");} return o;}
template<typename T>vector<T> & cset(vector<T> &A,T e=T()){for(auto &I:A){I=e;} return A;}







int main(){
    ll n,k,m;
    cin>>n>>k>>m;
    vector<vector<ll>> dp(2*n,vector<ll>(1LL<<k,0));
    vector<vector<ll>> nx(2*n,vector<ll>(1LL<<k,0));
    vector<ll> max_bit(1LL<<k,0);
    for(ll i=0;i<k;i++){
        for(ll j=0;j<(1LL<<k);j++){
            if(j>>i&1){max_bit[j]=1LL<<i;}
        }
    }
    dp[1][1]=1;
    for(ll i=1;i<n;i++){
        for(auto &I:nx){
            for(auto &T:I){T=0;}
        }
        for(ll j=i;j<2*i;j++){
            for(ll p=0;p<(1LL<<k);p++){
                //if(dp[j][p]==0){continue;}
                if(p+1==(1LL<<k) && i!=k){continue;}
                ll b=p;
                for(ll q=1;q<=k && j+q<(2*i+2);q++){
                    if(((b<<q)|1)>=(1LL<<k)){b^=max_bit[b]; continue;}
                    nx[j+q][(b<<q)|1]+=dp[j][p];
                    b^=max_bit[b];
                }
            }
        }
        for(auto &I:nx){
            for(auto &T:I){T%=m;}
        }
        swap(nx,dp);
        /*
        cout<<i+1<<endl;
        for(auto &I:dp){
            ll sum=0;
            for(auto &T:I){
                sum+=T;
            }
            cout<<sum<<" ";
        }
        cout<<endl;
         */
    }
    ll ans=0;
    for(ll i=n;i<2*n;i++){
        for(ll j=0;j<(1LL<<k);j++){
            if(j+1==(1LL<<k) && n!=k){continue;}
            ans+=dp[i][j];
            ans%=m;
        }
    }
    ans%=m;
    if(ans<0){ans+=m;}
    cout<<ans<<endl;
    
    
    
    
    return 0;
}
