#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l, r;
    while(cin >> n >> l >> r, n){
        int a[55];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        a[n] = 1;
        int cnt = 0;
        for(int y=l; y<=r; y++){
            for(int i=0;i<=n;i++){
                if(y%a[i]==0){
                    if(i%2==0)cnt++;
                    break;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}

