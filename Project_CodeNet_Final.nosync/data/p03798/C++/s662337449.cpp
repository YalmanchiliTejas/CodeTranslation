#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
// head
int n,ans,res;
char to[100100];
int main() {
	scanf("%d",&n);
	string s;
	std::cin >> s;
	to[0] = 'S';
	to[1] = 'S';
	rep(i,1,n){
		if (s[i] == 'o' && to[i] == 'S' && to[i-1] == 'S'){
			to[i+1] = 'S';
		}
		else if(s[i] == 'o' && to[i] == 'S' && to[i-1] == 'W'){
			to[i+1] = 'W';
		}
		else if(s[i] == 'o' && to[i] == 'W' && to[i-1] == 'S'){
			to[i+1] = 'W';
		}
		else if(s[i] == 'o' && to[i] == 'W' && to[i-1] == 'W'){
			to[i+1] = 'S';
		}
		else if(s[i] == 'x' && to[i] == 'S' && to[i-1] == 'S'){
			to[i+1] = 'W';
		}
		else if(s[i] == 'x' && to[i] == 'S' && to[i-1] == 'W'){
			to[i+1] = 'S';
		}
		else if(s[i] == 'x' && to[i] == 'W' && to[i-1] == 'W'){
			to[i+1] = 'W';
		}
		else if(s[i] == 'x' && to[i] == 'W' && to[i-1] == 'S'){
			to[i+1] = 'S';
		}
	}
	if (to[n] == to[0] && ((to[n-1] == 'S' && s[0] == 'o') || (to[n-1] == 'W' && s[0] == 'x'))){
		to[n] = '\0';
		std::cout << to << '\n';
	}
	else{
		char to[100100];
		to[0] = 'S';
		to[1] = 'W';
		rep(i,1,n){
			if (s[i] == 'o' && to[i] == 'S' && to[i-1] == 'S'){
				to[i+1] = 'S';
			}
			else if(s[i] == 'o' && to[i] == 'S' && to[i-1] == 'W'){
				to[i+1] = 'W';
			}
			else if(s[i] == 'o' && to[i] == 'W' && to[i-1] == 'S'){
				to[i+1] = 'W';
			}
			else if(s[i] == 'o' && to[i] == 'W' && to[i-1] == 'W'){
				to[i+1] = 'S';
			}
			else if(s[i] == 'x' && to[i] == 'S' && to[i-1] == 'S'){
				to[i+1] = 'W';
			}
			else if(s[i] == 'x' && to[i] == 'S' && to[i-1] == 'W'){
				to[i+1] = 'S';
			}
			else if(s[i] == 'x' && to[i] == 'W' && to[i-1] == 'W'){
				to[i+1] = 'W';
			}
			else if(s[i] == 'x' && to[i] == 'W' && to[i-1] == 'S'){
				to[i+1] = 'S';
			}
		}
		if (to[n] == to[0] && ((to[n-1] == 'W' && s[0] == 'o') || (to[n-1] == 'S' && s[0] == 'x'))){
			to[n] = '\0';
			std::cout << to << '\n';
		}
		else{
			to[0] = 'W';
			to[1] = 'S';
			rep(i,1,n){
				if (s[i] == 'o' && to[i] == 'S' && to[i-1] == 'S'){
					to[i+1] = 'S';
				}
				else if(s[i] == 'o' && to[i] == 'S' && to[i-1] == 'W'){
					to[i+1] = 'W';
				}
				else if(s[i] == 'o' && to[i] == 'W' && to[i-1] == 'S'){
					to[i+1] = 'W';
				}
				else if(s[i] == 'o' && to[i] == 'W' && to[i-1] == 'W'){
					to[i+1] = 'S';
				}
				else if(s[i] == 'x' && to[i] == 'S' && to[i-1] == 'S'){
					to[i+1] = 'W';
				}
				else if(s[i] == 'x' && to[i] == 'S' && to[i-1] == 'W'){
					to[i+1] = 'S';
				}
				else if(s[i] == 'x' && to[i] == 'W' && to[i-1] == 'W'){
					to[i+1] = 'W';
				}
				else if(s[i] == 'x' && to[i] == 'W' && to[i-1] == 'S'){
					to[i+1] = 'S';
				}
			}
			if (to[n] == to[0] && ((to[n-1] == 'W' && s[0] == 'o') || (to[n-1] == 'S' && s[0] == 'x'))){
				to[n] = '\0';
				std::cout << to << '\n';
			}
			else{
				to[0] = 'W';
				to[1] = 'W';
				rep(i,1,n){
					if (s[i] == 'o' && to[i] == 'S' && to[i-1] == 'S'){
						to[i+1] = 'S';
					}
					else if(s[i] == 'o' && to[i] == 'S' && to[i-1] == 'W'){
						to[i+1] = 'W';
					}
					else if(s[i] == 'o' && to[i] == 'W' && to[i-1] == 'S'){
						to[i+1] = 'W';
					}
					else if(s[i] == 'o' && to[i] == 'W' && to[i-1] == 'W'){
						to[i+1] = 'S';
					}
					else if(s[i] == 'x' && to[i] == 'S' && to[i-1] == 'S'){
						to[i+1] = 'W';
					}
					else if(s[i] == 'x' && to[i] == 'S' && to[i-1] == 'W'){
						to[i+1] = 'S';
					}
					else if(s[i] == 'x' && to[i] == 'W' && to[i-1] == 'W'){
						to[i+1] = 'W';
					}
					else if(s[i] == 'x' && to[i] == 'W' && to[i-1] == 'S'){
						to[i+1] = 'S';
					}
				}
				if (to[n] == to[0] && ((to[n-1] == 'S' && s[0] == 'o') || (to[n-1] == 'W' && s[0] == 'x'))){
					to[n] = '\0';
					std::cout << to << '\n';
				}
				else{
					std::cout << -1 << '\n';
				}
			}
		}
	}
}
