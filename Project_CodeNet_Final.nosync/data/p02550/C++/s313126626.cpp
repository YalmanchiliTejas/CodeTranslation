#include<bits/stdc++.h>
#define int long long
using namespace std;
void test_cases(){
    int n, x, m;
    cin >> n >> x >> m;
    int ans = x;
    set<int> s;
    s.insert(x);
    int i = 1;
    vector<int> v;
    v.push_back(0);
    v.push_back(x);
    while(i < n){
        x = (x * x) % m;
        if(x <= 1){
            break;
        }
        if(s.find(x) != s.end()){
            break;
        }
        s.insert(x);
        ans += x;
        v.push_back(x);
        i++;
    }
    if(x == 1){
        ans += (n - i);
    }
    else if(x > 1 && i < n){
        int k;
        for(k = 0; k <= i; k++){
            if(v[k] == x) break;
        }
        int len = i - k + 1;
        vector<int> pref(len + 1);
        pref[0] = 0;
        for(int j = k; j <= i; j++){
            pref[j - k + 1] = pref[j - k] + v[j];
        }
        int j = (n - i) / len;
        ans = ans + pref[i - k + 1] * j;
        j = (n - i) % len;
        ans += pref[j];
    }
    cout << ans << endl;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
//    cin >> tt;
    while(tt--){
        test_cases();
    }
    return 0;
}
