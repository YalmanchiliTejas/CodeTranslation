#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
#define chmin(a, b) ((a) = min((a), (b)))
#define chmax(a, b) ((a) = max((a), (b)))
#define fs first
#define sc second
#define eb emplace_back
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const double pi = acos(-1);
const double eps = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main(){
    int h, w; cin>>h>>w;
    vector<string> c(h);
    for(int i=0; i<h; i++) cin>>c[i];

    vector<int> plus;
    vector<int> minus;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(c[i][j] == 'B'){
                plus.emplace_back(j + i);
                minus.emplace_back(j - i);
            }
        }
    }

    sort(plus.begin(), plus.end());
    sort(minus.begin(), minus.end());

    int ma1 = plus[plus.size() - 1] - plus[0];
    int ma2 = minus[minus.size() - 1] - minus[0];

    cout << max(ma1, ma2) << endl;
}
