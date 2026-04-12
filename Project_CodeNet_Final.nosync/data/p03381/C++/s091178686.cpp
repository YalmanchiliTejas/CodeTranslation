#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <tuple>
#include <cstdio>
#include <bitset>
#include <sstream>
#include <iterator>
#include <numeric>
#include <map>
#include <cstring>

using namespace std;

#define DEBUG_ //!!提出時にコメントアウト!!
#ifdef DEBUG_
	#define dump(x)  cerr << #x << " = " << (x) << endl;
#else
	#define dump(x)  ; //何もしない文
#endif

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define SZ(x) ((int)(x).size()) //unsignedのサイズをint型に変換
#define pb push_back

typedef long long LL; 
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

template <typename T>
std::string printVector(const std::vector<T> &data)
{
    std::stringstream ss;
    std::ostream_iterator<T> out_it(ss, ", ");
    ss << "[";
    std::copy(data.begin(), data.end() - 1, out_it);
    ss << data.back() << "]";
    return ss.str();
}

const int MOD = 1e9+7;
const LL LINF = 1001002003004005006ll;
const int INF = 1001001001;

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);	
    int N; cin >> N;
    vector<pair<int,int>> X(N);
    REP(i,N)
    {
        int tmp; cin >> tmp;
        X[i] = make_pair(tmp, i);
    }
    sort(X.begin(), X.end());

    VI ans(N);

    REP(i,N)
    {
        if(i < N/2) 
        {
            ans[X[i].second] = X[N/2].first;
        }
        else ans[X[i].second] = X[N/2 - 1].first;
    }
    REP(i,N)
    {
        cout << ans[i] << endl;
    }

}
