#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

long long solve(int n, int a[]){
    long long ans = 0;
    long long ans2 = 0;
    if(n%2==0) {
        for(int i=0;i<n;i++) {
            if(i<(n-2)/2)
                ans += -2*a[i];
            else if(i==(n-2)/2)
                ans += -a[i];
            else if(i==n/2)
                ans += a[i];
            else
                ans += 2*a[i];
        }
        return ans;
    }else{
        for(int i=0;i<n;i++) {
            if(i<n/2)
                ans += -2*a[i];
            else if(i==n/2)
                ans += a[i];
            else if(i==(n+2)/2)
                ans += a[i];
            else
                ans += 2*a[i];
        }
        for(int i=0;i<n;i++) {
            if(i<(n-2)/2)
                ans2 += -2*a[i];
            else if(i==(n-2)/2)
                ans2 += -a[i];
            else if(i==n/2)
                ans2 += -a[i];
            else
                ans2 += 2*a[i];
        }
        return max(ans, ans2);
    }
}

int main(){
    int n;
    long long ans;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    sort(a, a+n);
    ans = solve(n, a);

    cout << ans << endl;

    return 0;
}
