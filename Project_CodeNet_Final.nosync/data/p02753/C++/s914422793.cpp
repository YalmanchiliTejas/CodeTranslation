#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
#define MAXN 501010

ll T,N,M,a,b;
ll A[MAXN];
vi V[MAXN];

int main(){
	string S;
	cin>>S;
	for (auto i:S)if(i=='A')++a;else ++b;
	if (min(a,b))cout<<"Yes";
	else cout<<"No";
}
