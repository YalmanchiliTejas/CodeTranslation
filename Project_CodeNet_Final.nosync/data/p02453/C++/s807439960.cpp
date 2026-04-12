#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[110000];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int q;
    cin >> q;
    for(int i=0; i<q; i++){
        int k;
        cin >> k;
        cout << lower_bound(a, a+n, k) - a << endl;
    }
    return 0;
}
