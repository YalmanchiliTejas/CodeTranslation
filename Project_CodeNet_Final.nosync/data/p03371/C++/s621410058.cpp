#include <bits/stdc++.h>
#include <cmath>
#include <numeric>
using namespace std;
using ll=long long;
#define rep(i,a,b) for(int i=(a); i<(b); ++i) // a ≦ i < b 
#define Rrep(i,a,b) for(int i=(a);i>=(b);--i) // reverse repeat. a から b まで減少．
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend() //逆イテレータ
#define RANGE(a,b,c) (a).begin()+b,(a).begin()+c // コンテナ a の 要素 b から c へのイテレータ
// typedef
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<PII> VP;

int main() {
int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
int mini = A * X + B * Y;

int maxXY = max(X,Y), yen;
rep(ab, 0, maxXY+1){
	yen = 2 * C * ab;
	if (X > ab) yen += A * (X - ab);
	if (Y > ab) yen += B * (Y - ab);
	mini = min(mini, yen);
	
}
cout << mini << "\n";

return 0;
}
