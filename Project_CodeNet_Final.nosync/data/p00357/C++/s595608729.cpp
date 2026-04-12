#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
 
ll n;
ll d[3 * 100005];
ll rd[3 * 100005];
ll sum[3 * 100005];
 
bool f(ll d[]);
 
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
     
    for (int i = n, k = 1; i > 0; i--, k++) {
        rd[k] = d[i];
    }
 
    bool l = f(d);
    bool r = f(rd);
 
    if (l && r) cout << "yes" << endl;
    else cout << "no" << endl;
 
    return 0;
}
 
bool f(ll d[]) {
    memset(sum, 0, sizeof(sum));
    sum[n] = 1;
 
    for (int i = n - 1; i > 0; i--) {
        ll r = min(n, i + d[i] / 10);
         
        //sum[i] += sum[i + 1];
        if (d[i] >= 10) {
            if (sum[i + 1] - sum[r + 1] > 0) {
                sum[i]++;
            }
        }
 
        sum[i] += sum[i + 1];
    }
 
    if (sum[1] > sum[2]) return true;
    else return false;
}
