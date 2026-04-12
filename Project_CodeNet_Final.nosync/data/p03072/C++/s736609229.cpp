#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, maxx=0, ans = 0, x;
    cin >> n;
    while(n--){
        cin >> x;
        if(x >= maxx){
            maxx = x;
            ++ans;
        }
    }
    cout << ans << "\n";
    return 0;
}
