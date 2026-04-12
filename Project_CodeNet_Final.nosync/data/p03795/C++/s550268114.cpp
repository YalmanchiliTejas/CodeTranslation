#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
#include<ctype.h>
#include<algorithm>
typedef long long int ll;
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#ifndef EVEL
#define DEB(X) cout << #X << ":" <<X<<" " ;
#define TF(f) f ? cout<<"true  " : cout<<"false ";
#define END cout<<"\n";
#else
#define DEB(X) {X;}
#define TF(f) {f;}
#define END {}
#endif

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define REP(i,n) for (int i=0;i<(n);i++)
#define EREP(i,a) for (int i=1;i<=(a);i++)
const ll MOD = (10*10*10*10*10*10*10*10*10+7);

    string A,B,C;
    int N,M,K,X,Y,W,H;
    int ans;
    string S;
    int temp[100]={0};
    bool f=true;
    bool fir=true;

int main(){
    cin>>N;
    cout<<N*800-(N/15)*200;

}
/*A.size()!=0&&B.size()!=0&&C.size()!=0*/
