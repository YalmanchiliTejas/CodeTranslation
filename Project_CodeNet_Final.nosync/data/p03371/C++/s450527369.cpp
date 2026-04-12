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
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int x = 0;
    int y = 0;
    int ans = 0;
    while ((x < X) && (y < Y) && ((A + B) > (C * 2)))
    {
        ++x;
        ++y;
        ans += C * 2;
    }
    while (x < X)
    {
        if (A > C * 2)
        {
            ++x;
            ans += C * 2;
        }
        else
        {
            ++x;
            ans += A;
        }
    }
    while (y < Y)
    {
        if (B > C * 2)
        {
            ++y;
            ans += C * 2;
        }
        else
        {
            ++y;
            ans += B;
        }
    }
    cout << ans << endl;
    return 0;
}
