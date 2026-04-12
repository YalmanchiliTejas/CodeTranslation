#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <random>
#include <chrono>
#include <queue>
#include <ctime>
#include <cassert>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
#define fs first
#define sc second
#define INF 1000000000
#define MOD 1000000007
#define EPS 0.00000001


int main() {
    int N; cin >> N;
    multiset<int> S;
    for(int i=0; i<N; i++){
        int a; cin >> a;
        auto it = S.lower_bound(a);
        if(it!=S.begin()) S.erase(--it);
        S.insert(a);
    }
    cout << S.size() << endl;
    return 0;
}
