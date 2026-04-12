#include <bits/stdc++.h>    
using namespace std;

#define CIN2(a,b) long long a,b;cin >> a >> b;
#define rep(i,n) for(int i=0,i##_len=(n); i<i##_len; ++i)

int main(){
    int n;cin >> n;
    vector<int> v(n);
    rep(i,n) cin >> v[i];
    int ans = 0,maxh = 0;
    rep(i,n){
        if(v[i]>=maxh){
            ans++;
            maxh = v[i];
        }
    }
    cout << ans << endl;
}

