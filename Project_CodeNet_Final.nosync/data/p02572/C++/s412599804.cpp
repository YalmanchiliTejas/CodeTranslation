#include <bits/stdc++.h>

#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define pi 3.14159265
#define oo 1000000007
#define loo 10000000000000007

#define prime 1000000007

#define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << "\n";
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vl v(n), sp(n);
    for (int i = 0; i < n; ++i){
    	cin >> v[i];
    	if(!i) sp[i] = v[i];
    	else{ 
    		sp[i] = (sp[i-1]+v[i])%prime;
    	}
    }
    ll ans = 0;
    for (int i = 0; i < n-1; ++i){
    	ans += (v[i]*(sp[n-1]+prime-sp[i])%prime)%prime;
    	ans%=prime;
    }
    cout << ans << "\n";

    return 0;
}