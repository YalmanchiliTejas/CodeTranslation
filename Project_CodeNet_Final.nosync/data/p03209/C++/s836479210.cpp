#include "bits/stdc++.h"
using namespace std;
#define repr(i,a,b) for(long long i=(long long)(a);i<(long long)(b);i++)
#define rep(i,n) repr(i,0,n)
#define reprrev(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);i--)
#define reprev(i,n) reprrev(i,0,n)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define mp make_pair
#define mt make_tuple
#define MOD 1000000007
#define PI 3.1415926535
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<Pi> vPi;
typedef vector<Pll> vPll;
typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;
typedef vector<vector<ll>> vvll;
typedef vector<vector<char>> vvc;
typedef vector<vector<string>> vvs;
typedef vector<vector<double>> vvd;
typedef vector<vector<Pi>> vvPi;
typedef priority_queue<int, vector<int>, greater<int>> pqli;
typedef priority_queue<ll, vector<ll>, greater<ll>> pqlll;
typedef priority_queue<Pi, vector<Pi>, greater<Pi>> pqlP;
string YN(bool y) { return (y?"YES":"NO"); }
string yn(bool y) { return (y?"Yes":"No"); }
string ON(bool y) { return (y?"OK":"NG"); }
int main(void)
{
	ll n, x;

	cin>>n>>x;

	vll p(n+1, 1), sum(n+1, 1);

	rep(i, n){
		p[i+1]=2*p[i]+1;
		sum[i+1]=2*sum[i]+3;
	}

	ll mid=(pow(2, n+2)-3)/2;
	ll ans=0;
	x--;
	reprev(i, n){
		//cout<<mid<<" "<<x<<endl;
		if(i==0){
			if(x>3){
				ans+=3;
			} else if(x>0){
				ans+=x;
			}
		} else{
			if(mid==x){
				ans+=p[i]+1;
				break;
			} else if(x<mid){
				x--;
			} else{
				ans+=p[i]+1;
				x-=mid+1;
			}
			if(mid>2){
				mid=mid/2-1;
			} else{
				mid=1;
			}
		}
	}
	cout<<ans<<endl;
}
