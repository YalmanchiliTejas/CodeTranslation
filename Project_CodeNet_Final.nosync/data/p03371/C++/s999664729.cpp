#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define CMAX(m, x)  m = max(m,x);
#define CMIN(m, x)  m = min(m,x);
#define itn int
typedef long long lint;
const int INF = 1e9;
const lint LINF = 1e18;
int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    lint sum = 0;
    if(2 * c > a + b){
        sum += a * x + b * y;
    } 
    else{
        if(x > y){
            lint suma = 2 * x * c;
            sum += 2 * y * c;
            sum += (x - y) * a;
            CMIN(sum, suma);
        }else{
            lint sumb = 2 * y * c;
            sum += 2 * x * c;
            sum += (y - x) * b;
            CMIN(sum, sumb);
        }
    }
    cout << sum << endl;
    return 0;
}