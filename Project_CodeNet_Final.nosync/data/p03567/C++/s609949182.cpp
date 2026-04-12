#include <bits/stdc++.h> 
 
using namespace std;
 
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

 
//typedef
//------------------------------------------
typedef pair<int, int> PII;
typedef pair<long, long> PLL;
typedef long long LL;

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
 
const LL INF=LONG_MAX;
const double EPS=0.00001;
const long double PI = acos(-1.0);

const int MAX_N=1e5;


int main(){
    string S;
    cin>>S;
    if(S.find("AC")!=std::string::npos){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}
