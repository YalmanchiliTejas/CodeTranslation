#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <deque>
using namespace std;

#define next '\n'
#define sp " "
#define print(x) cout << (x)
#define println(x) cout << (x) << next
#define stop return(0)
#define rep(i, n) for(int (i) = (0); (i) < (n); (++i))
#define FOR(i, start, end) for(int (i) = (start); (i) < (end); (++i))
#define foreach(e, elem) for(auto& (e) : (elem))
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr)
#define size(s) (s).size()
#define all(vec) (vec).begin(), (vec).end()
#define pb(e) push_back(e);
using ll = long long;
using ull = unsigned long long;

int main(){
    int n, k;
    string s;
    cin >> n >> s >> k;

    char c = s[k - 1];

    rep(i, n){
        if(s[i] != c){
            s[i] = '*';
        }
    }

    println(s);
}