#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
#include <cstdint>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, l, r) for (ll i = (ll)l; i < (ll)(r); i++)
#define INF 1000000000000000
#define MAX 200001

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
const ll MOD = 998244353;

template <typename T > inline string toString(const T &a) {ostringstream oss; oss << a; return oss.str();};

long long fac[MAX], finv[MAX], inv[MAX];

int main(){
    int N;
    cin >> N;
    string s;
    cin >> s;
    int K;
    cin >> K;
    K--;
    char d = s[K];
    rep(i,N){
        if(s[i] != d){
            s[i] = '*';
        }
    }
    cout << s << endl;
}