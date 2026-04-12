#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

int main(void){
    int n;
    cin >> n;
    int h[n];
    rep(i,n){
        int x;
        cin >> x;
        h[i] = x;
    }
    int nmax = 0;
    int ans = 0;
    rep(i,n){
        if(h[i] >= nmax){
            ans++;
            nmax = h[i];
        }
    }
    cout << ans <<endl;
    
    return 0;
}



