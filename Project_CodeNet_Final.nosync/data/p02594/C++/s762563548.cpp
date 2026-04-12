#include <bits/stdc++.h>
typedef long long ll;
#define mod 1000000007
#define INF 1000000000
#define endl "\n"
#define all(s) s.begin(),s.end()
#define pb push_back
#define uno unordered_map
#define pi 3.1415926536
#define dig(a) fixed<<setprecision(a)
#define test(zz) int zz; cin>>zz; while(zz--)
#define foreach(var,i) for(auto i = var.begin();i!=var.end();i++)
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL);
ll power(ll a, ll n) {ll res = 1; while (n) {if (n % 2) {res *= a;} n >>= 1; a *= a;} return res;}
ll powerm(ll a, ll n, ll m) {ll res = 1; while (n) {if (n % 2) {res = (res * a) % m;} n >>= 1; a = (a * a) % m;} return res;}
using namespace std;
int main(){
	fast();
	//test(t){}
	int x;cin>>x;
	cout<<(x>=30?"Yes":"No");
	return 0;
}
