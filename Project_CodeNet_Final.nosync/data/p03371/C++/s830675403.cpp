#include <bits/stdc++.h>
using namespace std;
#define repr(i,k,n) for(int i = (k); i < (n); i++)
#define rep(i,n) repr(i,0,n)
#define ALL(a) begin(a),end(a)
const int INF = 114514810;
const int MOD = 1000000007;
typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int A,B,C,X,Y;
	int ma,mi,sa,su;
	int yas,lap,meu;
	cin >> A >> B >> C >> X >> Y;
	if (X<Y){
		ma=Y;
		mi=X;
		sa=B;
		su=A;
	}else{
		ma=X;
		mi=Y;
		sa=A;
		su=B;
	}
	if (A+B<=C*2){
		cout << X*A+Y*B << endl;
	}else{
		yas=mi*C*2;
		if (sa>=C*2){
			yas+=2*C*abs(X-Y);
		}else{
			yas+=sa*abs(X-Y);
		}
		cout << yas << endl;
	}
}