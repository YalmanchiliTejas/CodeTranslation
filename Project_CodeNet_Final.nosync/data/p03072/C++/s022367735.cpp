#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main(){
    Hello
    int n;
    cin >> n;
    int mx = 0, ans = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(mx <= a) ans++;
        mx = max(mx, a);
    }
    cout << ans;
    return 0;
}
