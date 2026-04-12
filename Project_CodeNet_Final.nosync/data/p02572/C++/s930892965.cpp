#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=1000000007,MAX=100005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<ll> A(N),sum(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    
    sum[N-1]=A[N-1];
    for(int i=N-2;i>=0;i--){
        sum[i]=(sum[i+1]+A[i])%mod;
    }
    
    ll ans=0;
    
    for(int i=0;i+1<N;i++){
        ans+=A[i]*sum[i+1];
        ans%=mod;
    }
    
    cout<<ans<<endl;
}


