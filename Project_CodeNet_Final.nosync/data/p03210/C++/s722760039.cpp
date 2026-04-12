#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <algorithm>
#include <array>
#include <complex>
#include <string>
#include <utility>
#include <map>
#include <queue>
#include <list>
#include <functional>
#include <numeric>
#include <stack>
#include <tuple>

using namespace std;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
const int INF = 100000000;
const long long LINF = 1000000000000000000;
const int MOD = (int)1e9 + 7;
using pii = std::pair<int, int>;
#define SORT(v) std::sort(v.begin(), v.end())
int main(){
	int N,M,count=0;
    cin >> N;
    if(N==7||N==5||N==3) cout <<"YES"<<endl;
    else cout << "NO" <<endl;
    return 0;
}