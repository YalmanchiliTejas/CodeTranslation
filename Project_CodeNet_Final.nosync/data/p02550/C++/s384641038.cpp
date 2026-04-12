#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define endl '\n'

void solvetask(){
    long long n,x,m; cin >> n >> x >> m;
    map<long long, long long> pos;
    pos[x] = 1;
    vector<long long> a = {0, x};
    long long ans = x;
    for (long long i=2; i<=n; i++){
        x = x * x % m;
        if (pos[x]){
            long long remain = n - i, sum = 0;
            for (long long j=pos[x]; j < i; j++) sum += a[j];
            sum *= (n - i + 1) / (i - pos[x]);
            for (long long j=0; j < (n - i + 1) % (i - pos[x]); j++) sum += a[j + pos[x]];
            ans += sum;
            break;
        }
        ans += x;
        a.push_back(x);
        pos[x] = i;
    }
    cout << ans << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1; //cin >> t;
    while(t--) solvetask();
}