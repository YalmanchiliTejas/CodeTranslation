#include<iostream>
#include <list>
#include<stack>
#include<queue>
#include <vector>
#include <set>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#include<string>
#include <functional>

#define FOR(k,m,n) for(int (k)=(m);(k)<(n);(k)++)
#define REP(i,n) FOR((i),0,(n))
#define LL long long
#define CLR(a) memset((a),0,sizeof(a))
#define SZ(x) (int((x).size()))
#define WAITING(str) int str;std::cin>>str;
#define DEBUGING(str) cout<<str<<endl
using namespace std;

const LL MOD = 1000000007;// 10^9+7
const int INF = (1 << 30);


//変数
LL N, K;






//サブ関数
//入力
void input()
{
	cin >> N >> K;
}

//nの約数を列挙
vector<int> enum_div(int n)
{
	vector<int>res;
	for (int i = 1; i*i <= n; i++) {
		if (n%i == 0) {
			res.push_back(i);
			if (i*i != n) {
				res.push_back(n / i);
			}
		}
	}
	return res;
}

//計算
void calc()
{
	LL ans;
	if (K == 0) {
		ans = N * N;
	}
	else {
		ans = 0;
		FOR(b, K + 1, N + 1)
		{
			LL set = b - K;
			LL c = N / b;

			ans += set * c;
			if (c*b + K <= N) {
				ans += N - c * b - K + 1;
			}
		}
	}
	
	cout << ans << endl;
}


//出力
void output()
{

}


//デバッグ
void debug()
{
	int N;
	cin>>N;
}


//メイン関数
int main()
{
	input();
	calc();
	output();
	debug();
	
	return 0;
}
