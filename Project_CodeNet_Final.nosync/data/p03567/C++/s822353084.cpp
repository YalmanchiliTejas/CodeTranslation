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
const int MOD =  1000000007 ;
const int INF = 2000000000;


    string S;
    bool F=false;

int main(){
    cin>>S;
    REP(i,S.size()-1){
        if(S.substr(i,2)=="AC"){F=true;break;}
    }
    cout<<(F?"Yes":"No");
    return 0;

}
