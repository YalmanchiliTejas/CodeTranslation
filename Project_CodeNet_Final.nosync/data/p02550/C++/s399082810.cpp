#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define int long long

signed main(){
    // cout << fixed << setprecision(10) << flush;

    int n, x, m;
    cin >> n >> x >> m;
    vector<int> a;
    set<int> a_st;
    a.push_back(x);
    a_st.insert(x);
    for(int i=0; i<m; i++){
        x = (x*x) % m;
        if(a_st.find(x) != a_st.end()){
            break;
        }
        a.push_back(x);
        a_st.insert(x);
    }

    int start = 0;
    while(x != a[start]) start++;
    int ans = 0;
    if(n < start){
        for(int i=0; i<n; i++){
            ans += a[i];
        }
    }
    else{
        for(int i=0; i<start; i++){
            ans += a[i];
        }
        int fac = (n-start) / (a.size() - start);
        for(int i=start; i<a.size(); i++){
            ans += a[i] * fac;
        }
        for(int i=start; i<start+(n-start) % (a.size() - start); i++){
            ans += a[i];
        }
    }
    cout << ans << endl;

    return 0;
}