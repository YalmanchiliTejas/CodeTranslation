#include <array>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
#include <numeric>
#include <list>
#include <iomanip>
using namespace std;


typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

#define VV(T) vector<vector< T > >

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
	v.assign(a, vector<T>(b, t));
}

template <class F, class T>
void convert(const F &f, T &t){
	stringstream ss;
	ss << f;
	ss >> t;
}


#define REP(i,n) for(int i=0;i<int(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define PB push


#define MOD 1000000007LL
#define EPS 1e-10

int main()
{
    int n;
    cin >> n;
    int numAlphabet[26];
    REP(i, 26) numAlphabet[i] = 100;
    REP(i, n)
    {
        string S;
        cin >> S;
        int tmp[26];
        REP(i, 26) tmp[i] = 0;
        for (char c : S)
        {
            ++tmp[c - 'a'];
        }
        REP(i, 26) numAlphabet[i] = min(numAlphabet[i], tmp[i]);
    }
    string ans = "";
    REP(i, 26)
    {
        REP(j, numAlphabet[i])
        {
            ans += 'a' + i;
        }
    }
    cout << ans << endl;
    return 0;
}
