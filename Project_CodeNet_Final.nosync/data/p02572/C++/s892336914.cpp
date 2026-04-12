#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<long long>a(n);
    long long ans = 0, sum = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        sum += a[i];
        sum %= 1000000007LL;
    }
    
    for(int i=0; i<n-1; i++){
        sum -= a[i];
        if(sum<0) sum += 1000000007LL;
        ans += a[i]*sum;
        ans %= 1000000007LL;
        
    }
    cout << ans << endl;
    return 0;
}