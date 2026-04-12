#include "bits/stdc++.h"
using namespace std;

int main() {
    int n,ans = 1;
    cin >> n;
    vector<int>a(n);
    for(int i = 0;i<n;i++)cin >> a[i];
    for(int i = 1;i<n;i++){
        bool flag = true;
        for(int j = 0;j<i;j++){
            if(a[j] > a[i])flag = false;
        }
      	if(flag)ans++;
    }
    cout << ans;
    return 0;
}