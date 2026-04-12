#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define size(n) ( int( n.size() ) )
#define sqr(n) ( (n) * (n) )
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef long double ld;

ll ans = 0;
const int N = 55;
ll a[N];
int n;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for ( int i = 1; i <= n; i++ ){
        cin >> a[i];
    }
    int x;
    while(1){
        x = 0;
        for ( int i = 1; i <= n; i++ ){
            if ( a[i] > a[x] ){
                x = i;
            }
        }
        if ( a[x] <= n - 1 ){
            break;
        }
        ll cnt = ( a[x] - n + 1 ) / n;
        if ( ( a[x] - n + 1 ) % n != 0 ){
            cnt++;
        }
        ans += cnt;
        for ( int i = 1; i <= n; i++ ){
            if ( i == x ){
                a[i] -= cnt * n;
            }
            else{
                a[i] += cnt;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
