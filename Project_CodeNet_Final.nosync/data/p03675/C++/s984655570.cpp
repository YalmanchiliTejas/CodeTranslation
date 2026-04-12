#include <bits/stdc++.h>
const int MAX = 2e5 + 10;
typedef long long i64;
using namespace std;
const double EPS = 1e-6;

int ar[MAX];
int ars[MAX];
const int MOD = 1e9 + 7;
int main() {

    #ifdef LOCAL_DEBUG
    freopen ("data.in", "r", stdin );
    //freopen ("data.out", "w", stdout );
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define endl '\n'
    int n; cin >> n;


    for(int i = 0; i < n; i++)cin >> ar[i];

    for(int i = 0, j = n - 1; i <= (n-1) / 2; i++, j-= 2){
    	ars[i] = ar[j];
    	if(n - i - 1 != i)ars[n - i - 1] = ar[j - 1];
    }
    for(int i = 0; i < n ; i++)cout << ars[i] << (i == n - 1 ? '\n' : ' ');
}

