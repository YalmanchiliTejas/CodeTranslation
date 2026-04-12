#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fo(i,n) for(ll i=0;i<n;i++)
#define fok(i,k,n) for(ll i=k;i<n;i++)
#define ci(x) cin>>x
#define ci2(x,y) cin>>x>>y
#define co(x) cout<<x<<"\n"
#define co2(x,y) cout<<x<<" "<<y<<"\n"
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define PI 3.1415926535897932384626
#define deb1(x) cout<<#x<<" "<<x<<endl
#define deb2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<"\n"
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pll>		vpll;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
const int mod = 1000000007;	

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	ci(s);
	set<char> h;
	fo(i,3){
		h.insert(s[i]);
	}
	if((int)h.size()==2){
		co("Yes");
	}
	else{
		co("No");
	}
}
