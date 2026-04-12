#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n);++i)
using namespace std;
using ll = long long; 
using P = pair<int,int>;

template <class _T> inline bool chmax (_T& a,_T b){if(a<b){a=b;return true;}return false;}
template <class _T> inline bool chmin (_T& a,_T b){if(a>b){a=b;return true;}return false;}

const long long INF = 1LL << 60;

int main(void){
	int a,b,c,x,y;
	cin >> a >> b >> c >> x >>y;
	int X = max(x,y),Y = min(x,y);
	if(2*c >= a+b){
		cout << a*x + b*y << endl;
	}else{
		if(2*c <= a && x > y){cout << 2*c*Y + 2*c*(X-Y) << endl;return 0;}
		if(2*c <= b && y > x){cout << 2*c*Y + 2*c*(X-Y) << endl;return 0;}
		if(x>y)cout << 2*c*Y + a*(X-Y) << endl;
		else cout << 2*c*Y + b*(X-Y) << endl;
	}
	return 0;
}

