#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void p(vector<int> A){rep(i,A.size()){cout << A[i] << " ";}cout << "\n";}

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    ll ans;
    for(int i = 0;i <= 2*max(x,y);i++){
        if(i % 2 != 0)continue;
        ll p = c*i + a*(max(0,x-i/2)) + b*(max(0,y-i/2));
        //cout << p << endl;
        ans = min(ans,p);
    }
    cout << ans << "\n";
}