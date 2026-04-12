#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, ans = 0, prev = 0;
    cin >> n;
    for(int i = 0; i < n; ++i){
        int tmp; cin >> tmp;
        if(tmp >= prev)ans++;
        prev = max(tmp, prev);
    }
    cout << ans;
    return 0;

}
