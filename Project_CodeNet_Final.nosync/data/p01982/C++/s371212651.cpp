#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;


int main(){
    while(1) {
    int n, l, r; cin >> n >> l >> r;
    if(n==0 && l==0 && r==0) return 0;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int count=0;
    for(int i=l; i<=r; i++) {
        int res = -1;
        for(int j=0; j<n; j++) {
            if(i % a[j] == 0) {
                res = j;
                break;
            }
        }
        if(res % 2 == 0) count++;
        else if(n % 2 == 0 && res ==-1) count++; 
    }
    cout << count << endl;
    }
}
   
