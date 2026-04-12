#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>

#ifdef _MSC_VER
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}

//typedef
//------------------------------------------
typedef pair<int, int> PII;
typedef pair<long, long> PLL;
typedef long long LL;
//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const LL MOD=(LL)1e9+7;
//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

#define INF 1LL << 50


int main(){
    int N;
    cin>>N;
    LL a[200004];
    REP(i,N)cin>>a[i];
    vector<LL>res;
    int cnt=(N-(N%2))/2;
    while(cnt>0){
        res.PB(a[(2*cnt-1)]);
        cnt--;
    }
    cnt=0;
    while(cnt<N/2){
        res.PB(a[2*cnt]);
        cnt++;
    }
    if(N%2){
        res.PB(a[N-1]);
        reverse(ALL(res));        
    }
    REP(i,N){
        cout<<res[i];
        if(i!=N-1)cout<<" ";
        else cout<<endl;
    }
    return 0;
}