#include<bits/stdc++.h>
using namespace std;
#define ALL(obj) (obj).begin(), (obj).end()

#define endl "\n"
#define pb push_back
#define elif else if
#define cout_db cout << fixed

#define MOD 1000000007
#define PI 3.1415926
 
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

ll all[55];
ll count(int level, ll pos){
	if(level == 0) return 1;
	if(pos <= 1) return 0;
	if(pos <= all[level]/2) return count(level-1, pos-1);
	if(pos == all[level]/2 + 1) return 1 + count(level-1, pos-2);
	if(pos < all[level]) return 1+count(level-1,all[level-1])+count(level-1,pos-1-all[level]/2);
	return 1+2*count(level-1,all[level-1]);
}
int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	ll x;
	cin >> n >> x;

	all[0] = 1;
	for (int i = 1; i < n+1; i++) {
		all[i] = all[i-1]*2 + 3;
	}

	cout << count(n, x) << endl;

	return 0;
}