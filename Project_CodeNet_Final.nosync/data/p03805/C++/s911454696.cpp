/*-****************************************-*/

#define USE_CPP11

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#ifdef USE_CPP11
# include <unordered_set>
# include <unordered_map>
# include <array>
# include <valarray>
#endif // USE_CPP11

#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <ctime>
#include <climits>
#include <cassert>

using namespace std;

/*-****************************************-*/

typedef pair<int, int> pii;
typedef long long ll;

/*-****************************************-*/

#define mp make_pair

#define sz_array(a) (sizeof(a) / sizeof((a)[0]))

#define all(a) (a).begin(),(a).end()
#define r_all(a) (a).rbegin(), (a).rend()

#define exists(container, elem) ((container).find(elem) != (container).end())

/*-****************************************-*/

template<typename T> T MinAssign(T &a, T b) {
    if (a > b)
        a = b;
    return a;
}

template<typename T> T MaxAssign(T &a, T b) {
    if (a < b)
        a = b;
    return a;
}

template<typename T, size_t size> void Fill(void *ptr, T value) {
    fill((T *)ptr, (T *)ptr + size / sizeof(T), value);
}

/*-****************************************-*/

static const double EPS = 1e-10;
static const double PI = acos(-1.0);
static const int INF = 1 << 28;

/*-****************************************-*/

#ifdef DEBUG
#define ANSWER_PREFIX() cout << "[[ Answer ]] "
#else
#define ANSWER_PREFIX()
#endif // DEBUG

/*-****************************************-*/

//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////

constexpr int MaxN = 8 + 10, MaxM = 8 * (8 - 1) / 2 + 10;
int n, m;
vector<int> E[MaxN];
bool done[MaxN];

int Solve(int no, int remain) {
    if (remain == 0) {
        return 1;
    }

    done[no] = true;

    int ans = 0;
    for (auto& next : E[no]) {
        if (!done[next]) {
            ans += Solve(next, remain - 1);
        }
    }

    done[no] = false;
    return ans;
}

int main() {
    cin >> n >> m;

    for (size_t i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        E[a].push_back(b);
        E[b].push_back(a);
    }

    int ans = Solve(0, n - 1);
    ANSWER_PREFIX();
    cout << ans << endl;
}
