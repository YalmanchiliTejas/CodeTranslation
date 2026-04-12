#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

//inline int read(){int t = 0;int neg=1;char c;while((c=getchar_unlocked())!='\n'&&c!=' '&&c!=EOF){if(c=='-'){neg=-1;continue;}t=t*10+c-48;}return neg*t;}
//inline int readl(){long long t = 0;long long neg=1ll;char c;while((c=getchar_unlocked())!='\n'&&c!=' '&&c!=EOF){if(c=='-'){neg=-1ll;continue;}t=t*10+c-48;}return neg*t;}

#define debug(x) cout<<(#x)<<"="<<(x)<<", ";
#define debug1(x) debug(x) cout<<'\n';
#define debug2(x1, x2) debug(x1) debug(x2) cout<<'\n';
#define debug3(x1, x2, x3) debug(x1) debug(x2) debug(x3) cout<<'\n';
#define debug4(x1, x2, x3, x4) debug(x1) debug(x2) debug(x3) debug(x4) cout<<'\n';
#define debug5(x1, x2, x3, x4, x5) debug(x1) debug(x2) debug(x3) debug(x4) debug(x5) cout<<'\n';

typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<int,int> pi;
typedef pair<lli,lli> plli;
typedef vector<int> vi;
typedef vector<lli> vlli;
typedef vector<pi> vpi;
typedef vector<plli> vplli;
const lli M=1000000007ll;

int main(){
	fast_io 
	int n; cin>>n;
	int ans=n*800 -(n/15)*200;
	cout<<ans;
	
	return 0;
}