#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <math.h>
#include <assert.h>
#include <set>
#include <map>
#include <bitset>
#include <ctime>
#include <time.h>
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <stack>
#include <ctype.h>
#include <numeric>
#include <sstream>
#include <unistd.h>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <random>
#include <chrono>
#include <iomanip>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;
#define endl '\n'
#define debug(name) DEBUG(#name, (name))
template<typename T>
void DEBUG(string label, T value) {
    cerr << "[" << label << " = " << value << "]\n";
}

void solve(){
    ll N; cin >> N;
    int X, m;
    cin >> X >> m;
    map<int, int> pos;
    pos[X] = 0;
    int start = -1;
    int x = X;
    for(int i = 1; i < 2 * m; ++i){
        x = (1LL * x * x) % m;
        if(pos.count(x)){
            start = x;
            break;
        }
        pos[x] = i;
    }
    assert(start != -1);
    vector<int> seq = {start};
    while(true){
        int cur = (1LL * seq.back() * seq.back()) % m;
        if(cur == start)
            break;
        seq.push_back(cur);
    }
    vector<ll> pref = {seq[0]};
    for(int i = 1; i < (int)seq.size(); ++i){
        pref.push_back(pref.back() + seq[i]);
    }
    int u = (int)seq.size();
    if(N <= m){
        int cur = X;
        int sum = cur % m;
        for(int i = 1; i < N; ++i){
            cur = (1LL * cur * cur) % m;
            sum += cur;
        }
        cout << sum << endl;
        return;
    }
    int cur = X;
    ll sum_before = 0;
    for(int i = 0; i < m; ++i){
        sum_before += cur;
        if(cur == start){
            sum_before -= cur;
            N -= i;
            break;
        }
        cur = (1LL * cur * cur) % m;
    }
    ll sum = sum_before + 1LL * (N/u) * pref.back() + 1LL * (N % u == 0 ? 0 : pref[N % u - 1]);
    cout << sum << endl;




}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    solve();
}
