#include <bits/stdc++.h> 
 
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
//constant
//--------------------------------------------
//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

const LL INF=1e9;

int main(){
    LL N,K;
    cin>>N>>K;
    if(K==0){
        cout<<N*N<<endl;
        return 0;
    }
    LL tmp=0;
    LL sum=0;
    for(LL b=K+1;b<=N;b++){
        tmp=N/b*(b-K);
        if(N%b>=K-1){
            tmp+=(N%b-K+1);
        }
        //cout<<b<<" "<<tmp<<endl;
        sum+=tmp;
    }
    cout<<sum<<endl;
    return 0;
}
