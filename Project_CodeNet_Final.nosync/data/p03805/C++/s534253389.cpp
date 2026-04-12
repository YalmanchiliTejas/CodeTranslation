//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

//int→string
//string→int
//------------------------------------------
inline int toInt(string s) {
    int v;
    istringstream sin(s);
    sin >> v;
    return v;
}

template<class T>
inline string toString(T x) {
    ostringstream sout;
    sout << x;
    return sout.str();
}

//sqrt
//-------------------------------------------
template<class T>
inline T sqr(T x) { return x * x; }

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<VI> VVI;
typedef vector<VB> VVB;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i, c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s, e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define RSORT(c) sort((c).rbegin(),(c).rend())

//repetition
//------------------------------------------
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define REP(i, n)  FOR(i,0,n)
#define REPR(i, n) for(int i = n;i >= 0;i--)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI = acos(-1.0);

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;



int main() {

    int N;
    cin>>N;
    int M;
    cin>>M;

    VVB mapB;
    mapB.resize(N);
    REP(i, N){
        mapB[i].resize(N);
    }
    REP(i, N){
        REP(j,N){
            mapB[i][j] = false;
        }
    }
    REP(i, M){
        int a;
        int b;
        cin>>a>>b;
        mapB[a-1][b-1] = true;
        mapB[b-1][a-1] = true;
    }

    int p[10];
    REP(i,10){
        p[i] = i;
    }
    int count = 0;

    do{
        bool good = true;
        for(int i=0;i<N-1;i++){
            if(i==0){
                if(p[i]!=0){
                    good = false;
                }
            }
            if(mapB[p[i]][p[i+1]]){
                continue;
            }else{
                good = false;
            }
        }
        if(good){
            count++;
        }
    }while(next_permutation(p,p+N));

    cout<<count;

    return 0;
}




































































