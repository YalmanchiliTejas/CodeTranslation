#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

int main(void) {
    int n;
    cin>>n;
    int h[n];
    rep(i,n)cin>>h[i];
    int res=0;
    int mx=0;
    rep(i,n){
        if(h[i]>=mx){
            res++;
        }
        mx=max(mx,h[i]);
    }
    cout << res << endl;
    return 0;
}
