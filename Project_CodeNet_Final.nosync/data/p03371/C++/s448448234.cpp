#include<bits/stdc++.h>
using namespace std;

#define REP(i, n, m) for(int i = n; i < m; i++)
#define REPR(i, n, m) for(int i = n; i >= m; i--)
#define LREP(i, n, m) for(ll i = n; i < m; i++)
#define LREPR(i, n, m) for(ll i = n; i >= m; i--)


const int INF = 1e9 + 1;
const int MOD = 1e9 + 7;

typedef long long ll;


//---functions---//
int gcd(int a, int b){
    if(a < b) swap(a, b);
    return b?gcd(b, a%b):a;
}

int s2i(string num){stringstream ss; ss << num << flush; int n; ss >> n; return n;}
string i2s(int n){stringstream ss; ss << n << flush; return ss.str();}
//---------------//

ll A, B, C, X, Y;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> A >> B >> C >> X >> Y;
    if(2 * C >= A + B){
        cout << A * X + B * Y << endl;
    }else{
        int ans = 0;
        if(X >= Y){
            ans += Y * 2 * C;
            ans += min((X - Y) * A, (X - Y) * 2 * C);
            cout << ans  << endl;
        }else{
            ans += X * 2 * C;
            ans += min((Y - X) * B, (Y - X) * 2 * C);
            cout << ans  << endl;
        }
    }
}
