#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#define REP(i, m, n) for(int i=int(m);i<int(n);i++)
#define EACH(i, c) for (auto &(i): c)
#define all(c) begin(c),end(c)
#define EXIST(s, e) ((s).find(e)!=(s).end())
#define SORT(c) sort(begin(c),end(c))
#define pb emplace_back
#define MP make_pair
#define SZ(a) int((a).size())

//#define LOCAL 1
#ifdef LOCAL
#define DEBUG(s) cout << (s) << endl
#define dump(x)  cerr << #x << " = " << (x) << endl
#define BR cout << endl;
#else
#define DEBUG(s) do{}while(0)
#define dump(x) do{}while(0)
#define BR
#endif


//改造
typedef long long int ll;
using namespace std;




//ここから編集する



int main() {
    int N,M;
    cin >> N >> M;
    vector<vector<int> > e(N+1,vector<int>(N+1,0));
    REP(i,0,M){
        int a,b;
        cin >> a >> b;
        e[a][b] = 1;
        e[b][a] = 1;
    }
    vector<int> v(N);
    iota(v.begin(),v.end(),1);
    int ans = 0;
    do{
        int flag = true;
        REP(i,0,v.size() - 1){
            if(e[v[i]][v[i+1]] == 0){
                flag = false;
            }
        }
        if(flag) ans++;
    }while(next_permutation(v.begin()+1,v.end()));
    cout << ans << endl;
    return 0;
}
