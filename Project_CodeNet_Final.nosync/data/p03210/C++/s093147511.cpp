#include<bits/stdc++.h>                                                                                               
 
using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)
#define all(x) (x).begin(),(x).end()
#define int long long
using pii = pair<int,int>;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int x;
    cin >> x;
    if(x == 5 || x == 7 || x == 3) cout << "YES" << '\n';
    else cout << "NO" << '\n';  
    return 0;
}
