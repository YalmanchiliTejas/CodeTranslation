#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int choose(int n,int k) {
    int ans = 1;
    rep(i,k) ans *= n-i;
    rep(i,k) ans /= i+1;
    return ans;
}
int pow(int n,int k) {
    int ans = 1;
    rep(i,k) ans*=n;
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    string n;
    int k;
    cin >> n >> k;
    int num = n.size();
    int ans = 0;
    ans += choose(num-1,k) * pow(9,k);
    ans += (n[0]-'0'-1)*choose(num-1,k-1) * pow(9,k-1);
    if(k == 1) ans++;
    if(k == 2) {
        for(int i = 1; i <= num-1; i++) {
            bool flag = false;
            for(int k = 1; k <= i-1; k++) {
                if (n[k] != '0') {
                    flag = true;
                    break;
                }
            }
            if(flag) ans += 9;
            else ans+=(n[i] - '0');
        }
    }
    if(k==3) {
        for(int i = 1; i <= num-2; i++) for(int j = i+1; j <= num-1; j++) {
            bool flag = false;
            for(int k = 1; k <= i-1; k++) {
                if (n[k] != '0') {
                    flag = true;
                    break;
                }
            }
            if(flag) ans += 9*9;
            else{
                flag = false;
                for(int k = i+1; k <= j-1; k++) {
                    if (n[k] != '0') {
                        flag = true;
                        break;
                    }
                }
                if(flag) {
                    ans += (n[i]-'0')*9;
                } else if(n[i] != '0') {
                    ans += (n[i]-'0'-1)*9 + n[j]-'0';
                }
            }
        }
    }
    cout << ans << endl;
}
