#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    long long ans = 0, sum =0;
    int mod = 1000000000+7;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
        sum += a.at(i);
        
    }
 	 sum %= mod;
    for (int i = 0; i < N-1; i++) {
        sum -= a.at(i);
        if(sum<0) sum += mod;
        ans += sum * a.at(i);
        ans %= mod;
    }
    cout << ans << endl;
}
/*

*/
