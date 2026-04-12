#include<bits/stdc++.h>                                                                                               
 
using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)
#define reps(i,n) for(int i=1;i<=(n);++i)
//#define all(x) (x).begin(),(x).end()
#define int long long
using pii = pair<int,int>;
constexpr int INF  = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;

int a[200050];
string b;
signed main(){
    int n;
    cin >> n;
    rep(i,n) cin >> a[i];
    if(n % 2 == 0){ 
        for(int i = n-1;i >= 1;i -= 2){ 
            if(i == n-1) cout << a[i];
            else cout << ' ' << a[i];
        }
        for(int i = 0;i <= n-2;i += 2){ 
            cout << ' ' <<a[i];
        }
    }   
    else{
        for(int i = n-1;i >= 0;i -= 2){ 
            if(i == n-1) cout << a[i];
            else cout << ' ' << a[i];
        }
        for(int i = 1;i <= n-2;i += 2){ 
            cout << ' ' <<a[i];
        }
    }   
    cout << '\n';
    return 0;   
}
