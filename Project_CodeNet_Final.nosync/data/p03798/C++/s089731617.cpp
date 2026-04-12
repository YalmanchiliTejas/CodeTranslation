#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define lb lower_bound
#define ub upper_bound

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
//template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}

//head
int n;
string s;
bool works(int* a1){
	for(int i = 1; i < n -1; i++){
  		if(a1[i] == 0){
  			if(s[i] == 'o'){
  				if(a1[i+1] == -1)
  					a1[i+1] = a1[i-1];
  				else if(a1[i+1] != a1[i-1]) return false;
  			}
  			else{
  				if(a1[i+1] == -1)
  					a1[i+1] = a1[i-1] ^ 1;
  				else if(a1[i+1] != a1[i-1] ^ 1) return false;
  			}
  		}
  		else{
  			if(s[i] == 'o'){
  				if(a1[i+1] == -1)
  					a1[i+1] = a1[i-1] ^ 1;
  				else if(a1[i+1] != a1[i-1] ^ 1) return false;
  			}
  			else{
  				if(a1[i+1] == -1)
  					a1[i+1] = a1[i-1];
  				else if(a1[i+1] != a1[i-1]) return false;
  			}
  		}
  	}
  	return true;
}
void printans(int* a1){
	for(int i = 0; i < n; i++){
		if(a1[i] == 0){
			cout << 'S';
		}
		else{
			cout << 'W';
		}
	}
	cout << "\n";
}
int main()
{
	ios::sync_with_stdio(false);
  	cin.tie(0);

  	cin >> n;
  	cin >> s;
  	int a1[n];
  	int a2[n];
  	int a3[n];
  	int a4[n];
  	memset(a1, -1, sizeof(a1));
  	memset(a2, -1, sizeof(a2));
  	memset(a3, -1, sizeof(a3));
  	memset(a4, -1, sizeof(a4));

  	a1[0] = 0;
  	a1[n-1] = 0;
  	a2[0] = 0;
  	a2[n-1] = 1;
  	a3[0] = 1;
  	a3[n-1] = 0;
  	a4[0] = 1;
  	a4[n-1] = 1;
  	//if(n > 3){
	  	if(s[0] == 'o'){
	  		a1[1] = 0;
	  	}
	  	else{
	  		a1[1] = 1;
	  	}

	  	if(s[n-1] == 'o'){
	  		a1[n-2] = 0;
	  	}
	  	else{
	  		a1[n-2] = 1;
	  	}

  		if(s[0] == 'o'){
  			a2[1] = 1;
  		}
	  	else{
	  		a2[1] = 0;
	  	}

	  	if(s[n-1] == 'o'){
	  		a2[n-2] = 1;
	  	}
	  	else{
	  		a2[n-2] = 0;
	  	}

	  	if(s[0] == 'o'){
	  		a3[1] = 1;
	  	}
	  	else{
	  		a3[1] = 0;
	  	}

	  	if(s[n-1] == 'o'){
	  		a3[n-2] = 1;
	  	}
	  	else{
	  		a3[n-2] = 0;
	  	}

		if(s[0] == 'o'){
			a4[1] = 0;
		}
		else{
			a4[1] = 1;
		}

		if(s[n-1] == 'o'){
			a4[n-2] = 0;
		}
		else{
			a4[n-2] = 1;
		}
  	//}
  	if(works(a1)){
  		printans(a1);
  		return 0;
  	}
  	else if(works(a2)){
  		printans(a2);
  		return 0;
  	}
  	else if(works(a3)){
  		printans(a3); return 0;
  	}
  	else if(works(a4)){
  		printans(a4); return 0;
  	}
  	cout << -1 << "\n";
	return 0;
}
