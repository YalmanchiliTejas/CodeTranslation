#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int x=1;x<=100;x++){
        int sum = 0;
        bool ok = true;
        for(int i=0;i<n;i++){
            sum += a[i]-x;
            ok &= sum >= 0;
        }
        if(ok) ans = x;
        else break;
    }
    cout << ans << endl;
    return 0;
}

