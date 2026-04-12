// Created by sz
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll C(int n, int k){
    ll ans = 1;
    for (int i = n; i >= n-k+1; i--){
        ans *= i;
    }
    
    for (int i = 1; i <= k; i++){
        ans /= i;
    }
    return  ans;
}

int main(){
#ifdef LOCAL
    freopen("./input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string n;
    cin >> n;
    int k;
    cin >> k;
    
    int len = n.length();
    if(len == k){
        int nn = stoi(n);
        int cnt = 0;
        for (int i = 1; i <= nn; i++){
            string t = to_string(i);
            int ok = 1;
            if(t.length()!= k)continue;
            for (auto c : t) {
                if(c == '0') ok = 0;
            }
            if(ok) cnt++;
        }
        cout << cnt << "\n";
        return 0;
    }
    
    ll ans = 0;
    
 
    
    int cnt_nonezero = 0;
    for (int i = 0; i < len; i++){
        if(n[i]!='0'){
            cnt_nonezero ++;
            
            ll tmp =  C(len- i-1, k-cnt_nonezero+1);
             for (int i = 0; i < k-cnt_nonezero+1; i++){
                 tmp *= 9;
             }
            
            ll ttmp = (n[i] - '1') *  C(len-i-1, k-cnt_nonezero);
            for (int i = 0; i < k-cnt_nonezero; i++){
                ttmp *= 9;
            }
            
            tmp += ttmp;
            ans += tmp;
            if(cnt_nonezero >= k){
                ans ++;
                break;
            }
            
        }
        
    }
    cout << ans << "\n";
    
    
    return 0;
}
