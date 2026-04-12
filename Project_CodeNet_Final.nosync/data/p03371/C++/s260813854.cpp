#include <bits/stdc++.h>

#define rep(X,N) for(ll X = 0; X < (N); X++)
#define PI (acos(-1.0))
#define pback push_back
#define mpair make_pair
#define MODN 1000000007
#define ALL(V) (V).begin(),(V).end()
#define CERR if(false) cerr
#define INT_MAX_HALF (INT_MAX / 2)
#define EPS (1e-10)

using namespace std;

typedef long long ll;

int main(){

    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;

    int ans = INT_MAX;

    for(int i = 0; i <= 200000; i = i + 2){
        int tmp = i * c;

        tmp += max(x - i / 2, 0) * a;
        tmp += max(y - i / 2, 0) * b;

        ans = min(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}
