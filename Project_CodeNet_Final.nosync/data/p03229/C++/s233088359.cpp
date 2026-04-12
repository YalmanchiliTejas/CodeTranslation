#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    // cout << fixed << setprecision(10) << flush;

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int num = 0;
    int ans = 0;
    if(n == 2){
        cout << a[1] - a[0] << endl;
        return 0;
    }
    else if(n % 2 == 0 && n >= 4){
        int i = 0;
        int num = 0;
        for(i=1; i<n/2; i++){
            num += 2;
            ans += num * (a[i] - a[i-1]);
        }
        num += 1;
        ans += num * (a[i] - a[i-1]);
        i++;

        num--;
        ans += num * (a[i] - a[i-1]);
        i++;

        for(; i<n; i++){
            num -= 2;
            ans += num * (a[i] - a[i-1]);
        }
    }
    else if(n == 3){
        cout << max(2*a[2]-a[1]-a[0], a[2]+a[1]-2*a[0]) << endl;
        return 0;
    }
    else{
        int ans1 = 0, ans2 = 0;
        int num1 = 0, num2 = 0;
        int i;
        
        for(i=1; i<=n/2; i++){
            num1 += 2;
            ans1 += num1 * (a[i] - a[i-1]);
        }
        num1--;
        ans1 += num1 * (a[i] - a[i-1]);
        i++;
        num1--;
        ans1 += num1 * (a[i] - a[i-1]);
        i++;
        for(; i<n; i++){
            num1 -= 2;
            ans1 += num1 * (a[i] - a[i-1]);
        }

        for(i=1; i<n/2; i++){
            num2 += 2;
            ans2 += num2 * (a[i]-a[i-1]);            
        }
        num2++;
        ans2 += num2 * (a[i] - a[i-1]);
        i++;
        num2++;
        ans2 += num2 * (a[i] - a[i-1]);
        i++;
        for(; i<n; i++){
            num2 -=2;
            ans2 += num2 * (a[i] - a[i-1]);
        }

        ans = max(ans1, ans2);
    }
    cout << ans << endl;
    return 0;
}