#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define LLINF 9223372036854775807
#define MOD ll(1e9+7)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cerr<<#x<<": "<<x<<endl

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        bool is_OK = true;
        for(int j = 0; j < n; j++){
            if(i>j && h[i]<h[j]){is_OK = false;}
        }
        if(is_OK){ans++;}
    }
    cout << ans << endl;
    return 0;
}
