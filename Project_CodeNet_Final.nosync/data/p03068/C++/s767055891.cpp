#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <stack>
#include <iomanip>
#include <set>
#include <sstream>
#include <cmath>
#include <deque>
#include <list>
#include <bitset>
using namespace  std;
typedef pair<long long , long long> P;
typedef long long int64;
typedef long long lint;
#define REP(i, n) for(long long (i)=0; (i)<(n); ++i)
#define FOR(i, a, b) for(long long (i)=(a); (i)<(b); ++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define FST first
#define SND second

signed main(){
    int N, K;
    string s;
    cin >> N >> s >> K;
    char a = s[K-1];
    string res = "";
    REP(i, N){
        if(a==s[i]) res = res + a;
        else res = res + '*';
    }
    cout << res << endl;
    return 0;
}