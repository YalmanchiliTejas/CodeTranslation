#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <functional>
#include <cassert>
#include <utility>
#include <stack>
#include <queue>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,n1,n2) for(int i=n1;i<n2;i++)
#define speed_up    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef pair<int,int> Pi;
typedef long long int ll;
const int INF=(ll)(1<<30)-1;
const ll INFl=(ll)9223372036854775807;
const int MAX=10000;
const ll MOD=(ll)1e9+7;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a/gcd(a, b)*b;}


int a,b,c,x,y;

int main(){
	cin>>a>>b>>c>>x>>y;
	if(a+b<=2*c){
		cout<<a*x+b*y<<endl;
		return 0;
	}
	int ans=0;
	if(x>y){
		ans+=2*c*y;
		if(a>=2*c){
			ans+=2*c*(x-y);
		}else{
			ans+=a*(x-y);
		}
	}else{
		ans+=2*c*x;
		if(b>=2*c){
			ans+=2*c*(y-x);
		}else{
			ans+=b*(y-x);
		}
	}
	cout<<ans<<endl;
	return 0;
}
	