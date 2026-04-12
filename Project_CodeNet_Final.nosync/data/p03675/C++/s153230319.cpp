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
    REP(i,N){
        cin>>A;
        //DEB(N)END
        if (i==0||(N-i)%2==1)s.push_front(A);
        else s.push_back(A);

    }



    REP(i,s.size()){
        cout<<s[i];
        if(i!=(signed)s.size()-1)cout<<" ";
    }
    //cout<<ans;
    return 0;
}
