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
typedef long long int ll;
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define REP(i,n) for (unsigned int i=0;i<(n);i++)
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
const int MOD =  1000000007 ;
const int INF = 2000000000;


    ll A,B,C,D,N;
    ll ans=0;
    ll X[4];
    string S;
    bool F;
int main(){
    cin>>S;
    sort(ALL(S));
    F=(S[0]!=S[2]);
    cout<<(F?"Yes":"No")<<endl;

    return 0;
}
