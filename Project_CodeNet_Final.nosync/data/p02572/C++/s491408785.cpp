#include <bits/stdc++.h> 
#include <chrono>
using namespace std;
 
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
 
 
//typedef
//------------------------------------------
typedef pair<int, int> PII;
typedef long long LL;
typedef pair<LL, LL> PLL;
 
//container util
//------------------------------------------
#define PB emplace_back
#define MP make_pair 
#define SZ(a) int((a).size())
//repetition
//------------------------------------------
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define SORT(c) sort((c).begin(),(c).end())
#define ALL(a)  (a).begin(),(a).end()
//constant
//--------------------------------------------
//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))



int main(){
    int N;
    cin>>N;
    vector<LL>A(N),sum(N);
    LL allsum=0;
    const LL mod=1e9+7;
    REP(i,N){
        cin>>A[i];
        allsum+=A[i];
        allsum%=mod;
    }
    sum[0]=(allsum-A[0]+mod)%mod;
    FOR(i,1,N){
        sum[i]=(sum[i-1]-A[i]+mod)%mod;
    }
    LL res=0;
    
    REP(i,N){
        res+=(sum[i]*A[i])%mod;
        res%=mod;
    }
    cout<<res<<endl;
    return 0;
}