#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stack>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <iterator>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <regex>
#include <time.h>
#include <complex>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ld = long double;
#define pb push_back
#define mp make_pair
#define sc second
#define fr first
#define stpr setprecision
#define cYES cout<<"YES"<<endl
#define cNO cout<<"NO"<<endl
#define cYes cout<<"Yes"<<endl
#define cNo cout<<"No"<<endl
#define rep(i,n) for(ll i=0;i<(n);++i)
#define Rep(i,a,b) for(ll i=(a);i<(b);++i)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define rRep(i,a,b) for(int i=a;i>=b;i--)
#define crep(i) for(char i='a';i<='z';++i)
#define psortsecond(A,N) sort(A,A+N,[](const pii &a, const pii &b){return a.second<b.second;});
#define ALL(x) (x).begin(),(x).end()
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl;
#define endl '\n'
typedef long long ll;

int main(){

	int K, H, W, B, flag = 0, i, j, k, l, ans_0 = 0, ans_W = 0, len, max_i=0;
	double sum = 0.0;
	char N[101];
	long long dp[101][4][2] = {0};

	scanf("%s %d", N, &K);


	len = strlen(N);
//	printf("%d\n", len);


	dp[0][0][0] = 1;
	for (i = 0; i < len; i++){
		int temp = N[i] - '0';
		for (j = 0; j <= K; j++){
			for (k = 0; k < 2; k++){
				for (l = 0; l < 10; l++){ //桁だと10個の数字それぞれに対して判定するらしい
					int ni = i + 1, nj = j, nk = k;//i+1は次の遷移先 jは今までに非ゼロをj個使ってる仮定だから減ることはない、この桁で増えるのは高々1個なので++だけする　kは一致しているかしてないか
					if (l != 0) nj++;
					if (nj > K) continue;
					if (k == 0){
						if (l > temp) continue;
						if (l < temp) nk = 1;
					}
					dp[ni][nj][nk] += dp[i][j][k];
				}
			}

		}
	}


	int ans = dp[len][K][0] + dp[len][K][1];

	printf("%lld\n", ans);


	return 0;

}
    
