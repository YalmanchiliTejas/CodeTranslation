#include <iostream>
using namespace std;

#include <vector>
#define modes 1000000007;
int main(){
    long long sum=0;
    int n;cin >> n;
    vector<long long> a(n);
    for(int i=0; i<n; i++) {
        cin >> a.at(i);
        sum += a.at(i);
        sum %= modes;
    }
    long long ans = 0;
    for(int i=0; i<n; i++) {
        sum -= a.at(i);
        if(sum<0) sum += modes;
        ans += a.at(i)*sum;
        ans %= modes;
    }
    cout << ans << endl;
}