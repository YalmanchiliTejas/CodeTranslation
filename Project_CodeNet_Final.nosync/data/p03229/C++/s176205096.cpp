#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void){
    int n;
    long long ans = 0,ans2 = 0;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i++) cin >> a[i];
    sort(a.begin(), a.end());
    if(n %2 == 0){
        for(int i = n-1;i >= (n/2)+1;i--){
            ans += 2*a[i];
        }
        for(int i = 0;i < (n/2)-1;i++){
            ans -= 2*a[i];
        }
        ans += a[n/2];
        ans -= a[n/2-1];
    }else{
        for(int i = n-1;i >= (n/2)+1;i--){
            ans += 2*a[i];
        }
        for(int i = 0;i <= (n/2)-2;i++){
            ans -= 2*a[i];
        }
        ans -= a[n/2];
        ans -= a[n/2-1];
        
        for(int i = n-1;i >= (n/2)+2;i--){
            ans2 += 2*a[i];
        }
        for(int i = 0;i <= (n/2)-1;i++){
            ans2 -= 2*a[i];
        }
        ans2 += a[n/2+1];
        ans2 += a[n/2];
        ans = max(ans,ans2);
    }
    cout << ans << endl;
}
