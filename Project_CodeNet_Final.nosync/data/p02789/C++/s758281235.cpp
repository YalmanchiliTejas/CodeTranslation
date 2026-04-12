#include <bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
#define VSORT(v) sort(v.begin(), v.end());
#define VREV(v) reverse(v.begin(), v.end());
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vdouble = vector<double>;

int gcd(int a, int b) {
    if (b==0) return a;
   	else return gcd(b, a%b);
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}



int main(){
	ll N,M;
	cin>>N>>M;
	
	if(N==M)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}