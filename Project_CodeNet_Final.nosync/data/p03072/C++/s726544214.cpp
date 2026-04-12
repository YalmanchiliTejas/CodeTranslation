#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef vector<int> VI;
typedef vector<ll> VLL;

int main(){
    int n;
    cin >> n;
    VI h(n);
    
    for(int i = 0; i < n ; ++i)cin >> h[i];
    int ans =1, max = h[0];
    for(int i = 1; i<n ; ++i){
        if(max <= h[i]){
            ans++;
            max = h[i];
        }
    }

    cout << ans << endl;
    return 0;

}