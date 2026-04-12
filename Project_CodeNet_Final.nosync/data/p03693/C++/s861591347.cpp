#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
	if (b==0) return a;
    else{
    	return gcd(b,a%b);
    }
}
 
int main() {
	ll a,b,c;
  	cin >> a >> b >> c;
  	if((a*100+b*10+c)%4==0){
      cout << "YES" << endl;
    }
  	else{
      cout << "NO" << endl;
    }
}
