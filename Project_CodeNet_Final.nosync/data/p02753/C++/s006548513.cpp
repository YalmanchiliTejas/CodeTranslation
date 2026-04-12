#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define _USE_MATH_DEFINES
#include <math.h>
#define rep(i,n) for(int i = 0;i < n;i++)
#define NIL = -1;

int digit(ll x) {
    if (x / 10 == 0) return 1;
    return digit(x / 10) + 1;
}

ll gcd(long long a,long long b) {
    if (a < b) swap(a,b);
    if (b == 0) return a;
    
    return gcd(b,a%b);
}

ll lcm(ll a,ll b){
    a / gcd(a,b) * b;
}
const ll mod = 1e9 + 7;
const ll INF = 1e9 + 7;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};


/////////////////////////////////////////////////////////////////////////////////////////

int main(){
    string s;
    cin >> s;
    int a = 0,b = 0;
    for (int i = 0;i < s.size();i++){
        if (s[i] == 'A') a++;

        if (s[i] == 'B') b++;
    }

    if (a > 0 && b > 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}