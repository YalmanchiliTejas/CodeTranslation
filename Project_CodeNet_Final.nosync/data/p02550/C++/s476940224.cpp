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
    ll N,X,M;
    cin>>N>>X>>M;
    map<ll,ll> ind;
    v sums(M+1,0);

    sums[0] = X;
    ind[X] = 1;
    ll now = X;
    ll now_ind = 2;
    ll loop_sum = 0, loop_N =0;
    ll r = 0;//0-index

    while(true){
        now = (now*now)%M;
        sums[now_ind-1] = sums[now_ind-2] + now;
        if(ind[now] == 0){
            ind[now] = now_ind;
        }
        else{
            loop_sum = sums[now_ind-1] - sums[ind[now]-1];
            loop_N = now_ind - ind[now];
            r = ind[now]-1;
            break;
        }
        now_ind++;     
    }

    ll ans = 0;
    if(r < N-1){
        ans += sums[r];
        ll loops = (N-r-1)/loop_N;
        ans += loop_sum * loops;
        ans += sums[N-1- loops * loop_N] - sums[r];
    }
    else{
        ans = sums[N-1];
    }
    cout<<ans;

    return 0;
}