#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF = 1e9;
#define put(n) cout<<(n)<<endl
#define rep(i,N) for(int(i)=0;(i)<(N);++(i))
#define all(v) (v).begin() , (v).end()
#define rall(v) (v).rbegin() , (v).rend()
#define pb(n) push_back(n)


int main(){
    long N,K;
    cin >> N >> K;
    
    long ans = 0;
    for(long b=K+1;b<=N;++b){
        long Q = N/b;
        long P = N%b;
        ans += Q*max(0l,b-K)+max(P-K+1,0l);
    }
    if(K == 0) ans = N*N;

    cout << ans << endl;
}