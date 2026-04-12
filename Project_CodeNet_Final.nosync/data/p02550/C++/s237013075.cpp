#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int main(void){
    long long n, x, m;
    cin >> n >> x >> m;

    long long a = x, ans = 0;
    vector< long long > sum(m+1, 0);
    map< long long, int> mem;
    for(int i=1; ;i++){
        sum[i] = sum[i-1] + a;
        mem[ a ] = i;
        if(i == n){
            cout << sum[i] << endl;
            return 0;
        }
        a = a*a % m;
        auto itr = mem.find(a);
        if(itr == mem.end()) continue;
        int j = itr->second;
        int l = i-j+1;
        ans = sum[i] + (sum[i] - sum[j-1]) * ((n-i) / l);
        n = (n-i) % l;
        ans += sum[j-1+n] - sum[j-1];
        cout << ans << endl;
        return 0;
    }
}
