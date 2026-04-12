#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int com(int a, int b){
    int m = min(a-b, b);
    int ans = 1;
    b = m;
    rep(i, m){
        ans *= a;
        a--;
    }
    rep(i, m){
        ans /= b;
        b--;
    }
    cout << ans << endl;
    return ans;
}

int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.size();
    ll ans = 0;
    if(n >= 4){
        if(k == 1){
            ans += s.at(0)-'0';
            ans += (n-1)*9;
        }else if(k == 2){
            ans += (s.at(0)-'0'-1)*(n-1)*9;
            ans += (n-1)*(n-2)/2*9*9;
            int l = 1;
            while(s.at(l) == '0'){
                l++;
                if(l == n) break;
            }
            if(l != n){
                ans += (s.at(l)-'0');
                ans += (n-1-l)*9;
            }
        }else{
            ans += (s.at(0)-'0'-1)*(n-1)*(n-2)/2*9*9;
            ans += (n-1)*(n-2)*(n-3)/6*9*9*9;
            int l = 1;
            while(s.at(l) == '0'){
                l++;
                if(l == n-1) break;
            }
            if(l != n-1){
                ans += (s.at(l)-'0'-1)*(n-1-l)*9;
                ans += (n-1-l)*(n-2-l)/2*9*9;
                l++;
            }
            while(s.at(l) == '0'){
                l++;
                if(l == n) break;
            }
            if(l != n){
                ans += (s.at(l)-'0');
                ans += (n-1-l)*9;
            }
        }
    }else{
        int l = 0;
        rep(i, n) l += (s.at(i)-'0')*pow(10, n-1-i);
        rep(i, l){
            int m = i+1;
            int cou = 0;
            while(m != 0){
                if(m%10 != 0) cou++;
                m /= 10;
            }
            if(cou == k) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}