/**
 *      purpose : ABC 114 A
 *      author  : kyomukyomupurin
 *      created : 2018-12-02 21:00:19
**/

#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef pair<int, int> pii;
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define fi first
#define se second
#define print(x) cout << (x) << '\n'

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(__null);
    
    int x; cin >> x;
    if (x == 3 || x == 5 || x == 7) print("YES");
    else print("NO");
    
    return 0;
}