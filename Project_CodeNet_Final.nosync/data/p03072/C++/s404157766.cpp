#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    int ans=1;
    int m=h[0];
    for(int i=1; i<n; i++){
        if(m<=h[i]) ans++;
        m=max(m,h[i]);
    }
    cout << ans << endl;
return 0;
}