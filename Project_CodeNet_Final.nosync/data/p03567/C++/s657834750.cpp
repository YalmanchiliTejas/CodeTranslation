#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second

int main()
{
	string s;
	cin >> s;
	int n = s.length();
	for(int i=0; i+1<n; ++i){
		if(s[i]=='A' && s[i+1]=='C'){
			puts("Yes");
			return 0;
		}
	}
	puts("No");
	return 0;
}
