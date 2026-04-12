#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n;
    string s;
    cin >> s;
    cin >> k;

    string ans = "";
    for(int i = 0; i < n; i++){
        if(s[k - 1] != s[i]){
            ans += '*';
        }else{
            ans += s[i];
        }
    }

    cout << ans << endl;

    return 0;
}