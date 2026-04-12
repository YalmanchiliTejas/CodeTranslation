#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
typedef long long int ll;
typedef pair<int, int> P;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, k;
    string s;
    cin >> n >> s >> k;
    
    string ans = "";
    rep(i, n){
        if(s[i] != s[k - 1]){
            ans += "*";
        }else{
            ans += s[k-1];
        }
    }
    
    cout << ans << endl;

    return 0;
}