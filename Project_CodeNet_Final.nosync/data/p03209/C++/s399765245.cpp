#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll s[60];
ll p[60];

ll rec(ll n, ll x){
    if(n == 0) return 1;
    else if(x == 1) return 0;

    if(1 < x && x <= s[n-1] + 1) return rec(n-1, x-1);
    else if(s[n-1]+2 == x) return p[n-1] + 1;
    else if(s[n-1]+2 < x && x < s[n]) return p[n-1] + 1 + rec(n-1, x - s[n-1] - 2);
    else if(s[n] == x) return p[n];
}

int main(){
    ll n, x;
    cin >> n >> x;

	for(int i = 1; i < 60; i++){
        s[i-1] = (1LL<<(i+1)) - 3;
        p[i-1] = (1LL<<i) - 1;
	}
    cout << rec(n, x) << endl;
}