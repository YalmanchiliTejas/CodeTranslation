#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)


lli d[60];
lli p[60];
lli calc(lli level,lli num){
    if(level==0)return 1;
    
    if(num==0) return 0;
    if(num==d[level]-1)return p[level];
    if(num==(d[level]/2))return 1+p[level-1];
    if(0<num && num<(d[level])/2)return calc(level-1,num-1);
    return 1+p[level-1]+calc(level-1,num-d[level]/2-1);
}

void func(long long N, long long X){
    d[0] = 1;
    p[0] = 1;
    REP(i,1,60){
        d[i] = 2*d[i-1]+3;
        p[i] = 2*p[i-1]+1;
    }

    cout<<calc(N,X-1)<<endl;

}

int main(){
    // cout << fixed << setprecision(5);

    long long N;
    scanf("%lld",&N);
    long long X;
    scanf("%lld",&X);
    func(N, X);
    return 0;
}
