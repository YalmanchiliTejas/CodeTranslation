#include <iostream>
using namespace std;

int main() {
    int n, k;
    long long ans = 0;
    cin >> n >> k;
    if(k == 0){
        cout << (long long)n*n << endl;
        return 0;
    }
    for(int i=k+1;i<=n;i++){
        ans += (n / i) * (i - k);
        int t = n - (n / i)*i - k + 1;
        if(t > 0)ans += t;
    }
    cout << ans << endl;
	return 0;
}