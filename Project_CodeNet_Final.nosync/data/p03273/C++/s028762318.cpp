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


#define MOD 1000000007
#define INF 1001001001
#define MIN -1001001001
#define rep(i,k,N) for(int i=k;i<N;i++)
#define MP make_pair
#define MT make_tuple //tie,make_tuple は別物
#define PB push_back
#define PF push_front
#define all(x) (x).begin(),(x).end()


using namespace std;
typedef long long ll;
typedef vector<ll> v;
typedef vector<vector<ll>> vv;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
    ll H,W;
    cin>>H>>W;
    vector<string> A(H);
    rep(i,0,H)cin>>A[i];
    map<ll,ll> a,b;
    rep(i,0,H){
        bool ok = true;
        rep(j,0,W)if(A[i][j] == '#') ok = false;
        if(ok) a[i]++;
    }
    rep(i,0,W){
        bool ok = true;
        rep(j,0,H)if(A[j][i] =='#') ok = false;
        if(ok) b[i]++;
    }
    rep(i,0,H){rep(j,0,W){
        if(a[i] == 0&& b[j] == 0)cout<<A[i][j];
    }cout<<endl;}

    return 0;
}