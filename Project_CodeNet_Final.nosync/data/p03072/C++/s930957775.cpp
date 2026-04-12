#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = 0;
    int mx = 0;
    int cur;
    for (int i=0;i<n;i++){
        cin >> cur;
        mx = max(mx,cur);
        if (mx==cur)ans++;
    }
    cout << ans << endl;
}