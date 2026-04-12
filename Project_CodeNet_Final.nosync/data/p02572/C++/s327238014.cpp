//Hey u r too far away to know this
//CHIRAGA196
#include <bits/stdc++.h>
using namespace std;
#define     ff                  first
#define     pb                  push_back
#define     ss                  second
#define     IOS                 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define     all(v)              v.begin(), v.end()
#define     allr(v)             v.rbegin(), v.rend()
#define       int               long long
#define       endl             '\n'
const   int N = 1e6+5, Mod = 1e9 + 7;
int32_t main(){
        IOS;
      
        int n; cin >> n;
        vector<int> v(n);
        int sum = 0;
        for(auto &x:v){
            cin >> x, sum += x;
            sum %= Mod;
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            sum -= v[i];
            ans += (sum%Mod * v[i]%Mod)%Mod;
            ans %= Mod;
        }
        cout << (ans + Mod)%Mod;
        return 0;
}