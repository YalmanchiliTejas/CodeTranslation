#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<iomanip>
#include <utility>      // std::swap
typedef long long int ll;
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define REP(i,n) for (int i=0;i<signed(n);i++)
#define EREP(i,n) for (int i=1;i<=(n);i++)
#define ALL(a) (a).begin(),(a).end()
//#define EVEL 1

#ifdef EVEL
#define DEB(X) cout << #X << ":" <<X<<" " ;
#define TF(f) f ? cout<<"true  " : cout<<"false ";
#define END cout<<"\n";
#else
#define DEB(X) {}
#define TF(f) {}
#define END {}
#endif
const int MOD = 1000000007;
const ll INF = 200000000000;


    ll W,H,N,M;
    ll sum;
    ll ans=0;
    ll sm,lr;
    ll A;
    deque<ll> s;
    bool f=false;
int main(){
    ios_base::sync_with_stdio(false);
    cin>>N;
    A=N%2;
    REP(i,N){
        int a;
        cin>>a;
        if(i%2==A){
            s.push_back(a);
        }else{
            s.push_front(a);
        }
    }
    REP(i,N){
        cout<<s[i];
        if(i!=N-1)cout<<" ";
    }
    //cout<<ans;
    return 0;
}
