#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    int max_h = h[0];
    int cnt = 1;
    for (int i = 1; i < n; i++){
        if (max_h <= h[i]){
            cnt++;
            max_h = h[i];
        }
    }
    cout << cnt << endl;
    return 0;
}