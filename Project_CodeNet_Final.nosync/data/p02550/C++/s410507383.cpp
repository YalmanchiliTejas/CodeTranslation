#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main(){
	ll n, x, m;
  	cin >> n >> x >> m;
  	vector<int> id(m, -1);
  	vector<int> a;
 
  	ll len = 0, tot = 0;
  	while(id[x] == -1){
      	a.push_back(x);
    	id[x] = len;
      	len++;
      	tot += x;
      	x = (x*x)%m;
    }
  
  	int c = len-id[x];
  	ll s = 0;
  	for(int i = id[x]; i < len; i++) s += a[i];
  
  	ll ans = 0;
	if(n <= len){
    	rep(i, n) ans += a[i];
    } else {
    	ans += tot;
      	n -= len;
      	ans += s * (n/c);
      	n %= c;
      	rep(i, n) ans += a[id[x]+i];
    }
  
  	cout << ans << endl;
}