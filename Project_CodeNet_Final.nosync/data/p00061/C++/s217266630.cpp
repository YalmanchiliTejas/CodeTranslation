#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define repr(i,a,n) for(int i=a;i>=n;i--)
#define INF 999999999
#define INF_M 2147483647
#define pb(a) push_back(a)
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
 
int main() {
    map<int, int> a; // ??´???????????¨??£?§£??°????????????
    map<int ,int> m; // ??£?§£??°??¨??????????????????
    int x, y;
    while(~scanf("%d,%d\n", &x, &y)) {
        if(x == 0 && y == 0) break;
        a[x] = y; m[y];
    }

    int j = 1;
    for(auto &s : m) s.second = j++;
        
    int n;
    while(cin >> n) cout << j - m[a[n]] << endl;
    return 0;
}