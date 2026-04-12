#include<iostream>	// 入出力
#include<stdio.h>	// 入出力
#include<math.h>	// 数学の関数
#include<vector>	// 配列
#include<string>	// 文字列
#include<map>		// 連想配列
#include<stack>		// スタック
#include<queue>		// キュー
#include<algorithm> // ソートとか


using namespace std;

using ll = long long;

ll N, K;

int main()
{
	cin >> N >> K;

	ll ans = 0;

	if (K == 0) { cout << N*N << endl; return 0; }

	for (int b = K; b <= N; ++b)
	{

		ans += (b - K)*(N / b);
		
		if (N - b*(N / b) - K + 1 > 0)
		{
			ans += N - b*(N / b) - K + 1;
		}

		
		
	}

	
	

	cout << ans << endl;

	return 0;
}