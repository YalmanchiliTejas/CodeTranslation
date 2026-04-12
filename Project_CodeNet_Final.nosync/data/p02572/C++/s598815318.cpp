#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<map>
#include<set>
#include<tuple>
#include<cmath>
#include<iomanip>


using namespace std;
typedef long long ll;
typedef vector<ll> v;
typedef vector<vector<ll>> vv;


#define MOD 1000000007
#define INF 1001001001
#define MIN -1001001001
#define rep(i,k,N) for(int i=k;i<N;i++)
#define MP make_pair
#define MT make_tuple //tie,make_tuple は別物
#define PB push_back
#define PF push_front
#define all(x) (x).begin(),(x).end()


int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};


int main(){
    ll N;
    cin>>N;
    v A(N);
    rep(i,0,N)cin>>A[i];
    ll sum = 0;
    rep(i,0,N){
        sum += A[i];
        sum%=MOD;
    }
    sum += MOD;
    ll ans = 0;
    rep(i,0,N){
        sum -= A[i];
        sum += MOD;
        sum %= MOD;
        ans += (A[i] * sum) % MOD;
        ans %= MOD;
    }

    cout<<ans;
    return 0;
}