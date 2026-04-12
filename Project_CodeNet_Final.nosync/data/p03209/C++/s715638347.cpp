#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define what_is(x) cerr << #x << " is " << x << endl;
#define MT make_tuple
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define FOR(i,n) for (int i=0;i < n ; i++)
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
clock_t startTime;
long double getTime(){
	return (long double)(clock()-startTime)/CLOCKS_PER_SEC;
}

ll* bun;
ll* paty;
int n;
ll x;

ll f(int a, ll b){
	if(a==0) return 1;
	if(b==1) return (a==0)? 1: 0;
	ll m=bun[a-1];
	if(b <=m+1) return f(a-1,b-1);
	else if(b == m+2) return f(a-1,b-1)+1;
	else return  paty[a-1]+1+f(a-1,b-m-2);
	
}
// BBBPPPBPBPPPBBPBBPP 50 4321098765432109PBPBPPPBB B

int main(){
	startTime=clock();
	cin >> n >> x;
	
	bun=new ll[n+1];
	paty=new ll[n+1];
	bun[0]=1;
	paty[0]=1;
	for(int i=1;i < n+1;i++){
		bun[i]=bun[i-1]*2+3;
		paty[i]=paty[i-1]*2+1;
	}	
	
	cout << f(n,x);

	return 0;
}