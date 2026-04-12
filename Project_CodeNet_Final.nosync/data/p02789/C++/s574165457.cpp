#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<cmath>
using namespace std;

typedef pair<int, int> P;
typedef long long ll;
const int INF = 100000000;

ll gcd( ll a, ll b ){//最大公約数
    ll tmp;
    if( a < b ) { tmp = a; a = b; b = tmp; }
    if( b < 1 ) return -1;

    if( a % b == 0 ) return b;
    return gcd( b, a % b );
}
ll lcm(ll a, ll b){//最小公倍数
    return a * b / gcd(a, b);
}
ll sosuu(ll x){
    for(int i = 2; i < x; i++){
        if(x % i == 0) return false;
    }

    return true;
}


//入力


int main(){

    int n, m;
    cin >> n >> m;

    if(n == m) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}