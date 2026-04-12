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
#include<set>
#include<map>
typedef long long int ll;
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define REP(i,n) for (int i=0;i<(n);i++)
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
const ll MOD = 1000000007;
const int INF = 2000000000;

    ll N,M;
    ll A,B,C;
    std::string S[200],T[200];
    bool F=true;
    ll ans=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin>>A>>B;
    REP(i,A)cin>>S[i];
    REP(i,B){REP(j,A){
        DEB(S[j][i])
        if(S[j][i]=='#'){
            DEB(i)DEB(j)END
            REP(k,A)T[k]+=S[k][i];
            break;
        }
    }END}
    REP(i,A){
        bool f=false;
        REP(j,(signed)T[i].size()){
            if(T[i][j]=='#')f=true;
        }
        if(f)cout<<T[i]<<endl;
    }
    return 0;
}
