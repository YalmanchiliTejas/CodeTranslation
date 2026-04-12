#include<bits/stdc++.h>
using namespace std;
#define ALL(obj) (obj).begin(), (obj).end()
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)

#define endl "\n"
#define pb push_back
#define elif else if
#define cout_db cout << fixed

#define MOD 1000000007
 
const int dx[]={1,0,-1,0}, dy[]={0,-1,0,1};
const int dx_8[]={1,1,0,-1,-1,-1,0,1}, dy_8[]={0,-1,-1,-1,0,1,1,1};

typedef long long ll;

template <typename T>
inline T GCD(T a,T b){T c;while(b!=0){c=a%b;a=b;b=c;}return a;}
template <typename T>
inline T LCM(T a,T b){T c=GCD(a,b);a/=c;return a*b;}
template <typename T>
inline T nCr(T a,T b){T i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}
template <typename T>
inline T nHr(T a,T b){return nCr(a+b-1,b);}
template <typename T>
inline T POW(T a,T b){int i,r=1;for(i=1;i<=b;i++){r*=a;}return r;}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	ll a[100000];
	cin >> n;
	REP(i, n) cin >> a[i];

	sort(a, a+n);

	int p = (n-1) / 2;
	int q = n-2-p;

	ll pts = 0, pt = 0;

	if(n % 2 == 1){
		REP(i, n){
			if(i < p) pts -= 2*a[i];
			elif(i >= n-q) pts += 2*a[i];
			else pts += a[i];
		}
		REP(i, n){
			if(i < q) pt -= 2*a[i];
			elif(i >= n-p) pt += 2*a[i];
			else pt -= a[i];
		}
	}
	else{
		REP(i, n){
			if(i < p) pts -= 2*a[i];
			elif(i >= n-q) pts += 2*a[i];
			elif(i == p) pts -= a[i];
			else pts += a[i];
		}
		REP(i, n){
			if(i < q) pt -= 2*a[i];
			elif(i >= n-p) pt += 2*a[i];
			elif(i == q) pt -= a[i];
			else pt += a[i];
		}
	}

	cout << max(pts, pt) << endl;
	
	return 0;
}