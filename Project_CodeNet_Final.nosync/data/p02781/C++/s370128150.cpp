#include<algorithm>
#include<cmath>
#include<cstdio>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<string>
#include<utility>
#include<vector>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
#define repl(i,s,e) for(int i=s;i<e;i++)
#define reple(i,s,e) for(int i=s;i<=e;i++)
#define revrep(i,n) for(int i=n-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()

int main()
{	
	string N;
	cin >> N;

	int K;
	cin >> K;

	//dp0[i][j] := 上からi桁目まで決めて、0でない桁がj個あり、Nより小さいことが確定している
    //dp1[i][j] := 上からi桁目まで決めて、0でない桁がj個あり、Nより小さいことが確定していない
	vector<vector<ll>> dp0(N.size() + 1, vector<ll>(K + 1, 0));
	vector<vector<ll>> dp1(N.size() + 1, vector<ll>(K + 1, 0));
	
	
	dp1[0][0] = 1;

	rep(i, N.size())
	{
		int d = N[i] - '0';

		reple(j, 0, 9)
		{
			if (j == 0)
			{
				//0の場合個数を増やさない
				reple(k, 0, K)
				{
					dp0[i + 1][k] += dp0[i][k];

					if (j < d)
					{
						//N[i]より小さい・・・Nより必ず小さい
						dp0[i + 1][k] += dp1[i][k];
					}
					else if(j == d)
					{
						//N[i]以下・・・Nより小さいかわからない
						dp1[i + 1][k] += dp1[i][k];
					}
				}
			}
			else
			{
				rep(k, K)
				{
					dp0[i + 1][k + 1] += dp0[i][k];

					if (j < d)
					{
						//N[i]より小さい・・・Nより必ず小さい
						dp0[i + 1][k + 1] += dp1[i][k];
					}
					else if (j == d)
					{
						//N[i]以下・・・Nより小さいかわからない
						dp1[i + 1][k + 1] += dp1[i][k];
					}
				}
			}
		}
	}

	cout << dp0[N.size()][K] + dp1[N.size()][K] << endl;

	return 0;
}