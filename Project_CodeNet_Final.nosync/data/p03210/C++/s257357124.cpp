// ConsoleApplication69.cpp : アプリケーションのエントリ ポイントを定義します
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<utility>
#include<queue>
#include<cmath>
using namespace std;
#define REP(i, a,b) for(i=a;i<b;i++) 
#define REP1(i,b,a) for(i=b-1;i>=a;i--)
#define output(x) cout<<x<<endl;
#define pb(x) push_back(x);
typedef long long int ll;
const int MAX = 510000;
const int MOD = 1000000007;


int main()
{
	ll i, j, k, l, m, flag, N, M,K;

	flag = 0;
	cin >> N;
	if (N == 3 || N == 5 || N == 7) {
		output("YES");
	}
	else
	{
		output("NO");
	}
	
	return 0;
}

