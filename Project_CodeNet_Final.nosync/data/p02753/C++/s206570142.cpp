#include <iostream>
// #include <cassert>
#include <vector>
#include <algorithm>
#include <climits>


// #include <deque>
// #include <stack>
// #include <set>
// #include <map>
// #include <string>
// #include <unordered_set>
// #include <unordered_map>
// #include <queue>
// #include <tuple>

// #include <cmath>
// #include <numeric>

using namespace std;
typedef long long ll;
typedef long l;
typedef pair<long,long> pll;
typedef pair<int,int> pii;
typedef pair<int,long> pil;
typedef pair<long,int> pli;
const char el = '\n';

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    // int T;
    // cin>>T;
    // cin.ignore();

    // for (int t=0; t<T; ++t) {
        
    // }

    string s;
    cin>>s; cin.ignore();
    bool sawa=false; bool sawb=false;
    for (char c: s) {
        if (c=='A') {
            sawa=true;
        }
        if (c=='B') {
            sawb=true;
        }
    }

    if (sawa&&sawb) {
        cout<<"Yes"<<el;
    } else {
        cout<<"No"<<el;
    }
    
    // long n, m;
    // cin>>n>>m; cin.ignore();

}

