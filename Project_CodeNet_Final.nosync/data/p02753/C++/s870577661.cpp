#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
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

int main() {
    FAST;

    string s;
    cin >> s;

    int A = 0, B = 0;
    rep(i, size(s)){
        if(s[i] == 'A') A++;
        else B++;
    }

    if(A >= 1 && B >= 1){
        println("Yes");
    }else{
        println("No");
    }
}