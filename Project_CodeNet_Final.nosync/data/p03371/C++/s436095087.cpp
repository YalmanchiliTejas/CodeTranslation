#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(int)(n); i<i##_len; i++)
#define reps(i,n) for(int i=1 , i##_len=(int)(n);i<=i##_len;i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define rreps(i,n) for(int i=((int)(n));i>0;i--)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
typedef vector<long long> V;
typedef vector<V> VV;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
const long long INFLL = 1LL<<60;
const int INF = 1<<28;
void solve(int a){cout<<( a?"Yes":"No")<<endl;}
int main(){
	int a,b,c,x,y;
	int ans=0;
	int bc=0;
	cin >>a>>b>>c>>x>>y;
	if((a+b)> c*2){
		bc=min(x,y);
		ans=+bc*2*c;
		//cout<<ans<<endl;
		x-=bc;
		y-=bc;
		if(x==0){
			if(b >c*2){
				ans+=y*2*c;
				//cout << ans << endl;
				y=0;
			}
		}else{
			if(a>c*2){
				ans+=x*2*c;
			//	cout << ans << endl;
				x=0;
			}
		}
	}
	ans+=x*a;
	//cout << ans << endl;
	ans+=y*b;
	//cout << ans << endl;
	cout<<ans<<endl;
}