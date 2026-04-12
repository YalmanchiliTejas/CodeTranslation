#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())
#define ALL(x) (x).begin(),(x).end()
const long long MOD = 1000000007;
const long long INF = 1LL << 60;


int main(){
	int H, W;
	cin >> H >> W;
	int Scnt = 0;
	rep(i, H * W){
		char S;
		cin >> S;
		if(S == '#')Scnt++;
	}
	cout << ((Scnt == H + W - 1) ? "Possible" : "Impossible") << endl;
}