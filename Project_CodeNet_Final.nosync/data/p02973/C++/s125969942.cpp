#include <cstdio>
#include <iostream>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <limits>
#include <numeric>
#include <type_traits>
#include <queue>
#include <cmath>
#include <queue>
#include <set>
#include <map>

using namespace std;

#define INF (1ll<<60)
#define INFint (1<<30)
#define MOD 1000000007
#define BOUND 27182818284

typedef long long ll;
typedef long long int lli;
typedef pair<ll, ll> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for(int i=int(a);i<int(b);++i)

template<class T>
bool umax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool umin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

// gcd
template<typename T>
T gcd(T a, T b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int findGCD(int arr[], int n) {
    int result = arr[0];
    for (int i = 1; i < n; i++)
        result = gcd(arr[i], result);
    return result;
}

template<typename T>
T lcm(T m, T n) {
    // 引数に0がある場合は0を返す
    if ((0 == m) || (0 == n))
        return 0;
    return ((m / gcd(m, n)) * n); // lcm = m * n / gcd(m,n)
}

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
    fill((T *) array, (T *) (array + N), val);
}


int dx[5] = {1, 0, -1, 0};
int dy[5] = {0, 1, 0, -1};

// v.front() = -BOUND;
// v.back() = BOUND;

//struct edge{
//    int cost, to;
//
//    edge(int in_cost, int in_to){
//        cost=in_cost;
//        to=in_to;
//    }
//    bool operator<(const edge &a) const
//    {
//        return cost > a.cost;
//    }
//};
vector<int> G[200010];
vector<int> c(10010, 0);
int num[200010];
bool used[200010];
int now_c = 0;

int dfs(int s) {
    if (used[s]) {
        return 0;
    } else {
        used[s] = true;
    }

    num[s] = c[now_c];
    now_c++;

    for (int i = 0; i < G[s].size(); i++) {
        dfs(G[s][i]);
    }
    return 0;
}

int main() {
    int N; cin >> N;
    vector<int> a(N);

    rep(i,N){
        cin >> a[i];
    }

    multiset<int> st;

    st.insert(a[0]);

    for(int i=1; i<N; i++){
        auto ptr = st.lower_bound(a[i]);
        if(ptr == st.end()){
            st.erase(--st.end());
            st.insert(a[i]);
        }else{
            if(ptr==st.begin()) {
                st.insert(a[i]);
            }else{
                ptr--;
                st.erase(ptr);
                st.insert(a[i]);
            }
        }
    }
    cout << st.size() << endl;
    return 0;
}