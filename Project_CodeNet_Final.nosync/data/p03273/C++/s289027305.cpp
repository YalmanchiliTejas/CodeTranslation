#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
#include <cstdlib>
#define rep(i,x) for(int i=0;i<x;i++)
#define all(a) (a).begin(),(a).end()
using namespace std;
using ld = long double;
using ll = long long;
const ll INF = 10010010010;
typedef pair<ll, ll> P;
const ll mod = 1000000007;
ll gcd(ll a, ll b) {//a>b
    if (a < b)swap(a, b);
    if (a % b == 0) return b;
    else return gcd(b, a % b);
}

int main() {
    ll N, M;
    cin >> N >> M;
    vector<bool> tate(N,false);
    vector<bool> yoko(M,false);
    vector<vector<char>> word(N, vector<char>(M));
    rep(i, N) {
        rep(j, M) {
            cin >> word[i][j];
            if (word[i][j] == '#') {
                tate[i] = true;
                yoko[j] = true;
            }
        }
    }
    rep(i, N) {
        rep(j, M) {
            if (tate[i] == true && yoko[j] == true)cout << word[i][j];
            
        }
        if(tate[i] == true)
        cout << endl;
    }
}
