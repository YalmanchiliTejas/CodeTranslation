#include <iostream>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstdarg>
#include <set>
#include <limits>
#include <iomanip>

using namespace std;
#define INF 2e9 + 9
#define MOD 1000000007
#define ALL(v) v.begin() , v.end()
#define Int int64_t
#define pll pair<Int,Int>
template<class T> using pql = priority_queue<T, vector<T>>;
template<class T> using pq = priority_queue<T, vector<T>, greater<T>>;
#define ll(n) Int n; cin >> n;
#define LL(...) Int __VA_ARGS___; cin >> __VA_ARGS___;
#define OUT(...) cout << __VA_ARGS___;
#define RP(n, i, s) for(Int i = s ;i < n ;i++)
#define REP(n, i) for (Int i = 0; i < n; i++)
#define REPe(n, i) for (Int i = 1; i <= n; i++)
#define RPe(n, i, s) for (Int i = s; i <= n; i++)
#define upd_max(maxer, updater) if (maxer < updater) maxer = updater;

void ansYes(bool flag){
    if (flag) cout << "Yes" << endl; else  cout << "No" << endl;
}

void ansYES(bool flag){
    if (flag) cout << "YES" << endl; else  cout << "NO" << endl;
}

struct node {
    Int to;
    Int length;
};


vector<Int> divisor(Int n) {
    vector<Int> ret;
    for (Int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    return (ret);
}

/*
vector<vector<int>> to;
vector<int> flag;
vector<int> c;


Int dfs(int from, int mae) {
    flag[from] = 1;
    Int mini = 0;
    for (auto next : to[from]) {
        if (next == mae) continue;
        if (flag[next] == 1) {
            return -1;
        } else {
            mini = min(mini, dfs(next, from));
        }
    }
    return mini;
}*/

int dx8[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int nanko(string s,Int n,Int i){
    Int length = min(n - i - 1,i);
    Int ans = 0;
    for (int k = i-length;k < i;k++){
        if (s.at(k) == 'R' && s.at(i +  (i - k) == 'B')) ans++;
    }
    return ans;
}

int main(){
    Int n;
    cin >> n;
    multiset<Int,greater<>> s;
    Int z;
    cin >> z;
    s.insert(z);
    REP(n - 1,i) {
        Int x;
        cin >> x;
        //cout << "Hello ";
        //cout << *s.rbegin() << " < kusa";
        if (*s.rbegin() >= x) {
            //cout << *s.rbegin() << endl;
            s.insert(x);
            //cout << "Hello 2";
        }else{
            auto it = s.upper_bound(x);
            s.erase(it);
            s.insert(x);
            //cout << "Hello 3";
        }
        /*for( auto z: s) {
            cout << z << " ";
        }
        cout << endl;*/
    }
    cout << s.size() << endl;

}