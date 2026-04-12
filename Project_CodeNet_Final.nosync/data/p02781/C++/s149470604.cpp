#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <utility>
#include <tuple>
#include <cctype>
#include <bitset>
#include <complex>
#include <cmath>
#include <array>
#include <numeric>
using namespace std;
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL
//#define MOD 998244353
#define MOD 1000000007
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pint;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pint> vpint;
int dx[8]={0,0,-1,1,1,1,-1,-1};
int dy[8]={-1,1,0,0,1,-1,1,-1};
const int SIZE=150;
//↑templete
#define int long long
signed main(){

	string S;
	cin>>S;
	int K;
	cin>>K;

	int N=S.length();
	reverse(S.begin(), S.end());

	ll DP[SIZE][SIZE][2]={};	//DP[i][j]=i桁の数字でSの上からi桁より小さいもののなかで、0でない数字がj個のものの数
	DP[N][0][0]=1;
	for(int i=N;i>=1;i--){
		for(int j=0;j<=K;j++){
			for(int k=0;k<=9;k++){
				int now=S[i-1]-'0';

				//すでに小さいことが確定している遷移
				if(k==0)
					DP[i-1][j][1] += DP[i][j][1];
				else
					DP[i-1][j+1][1] += DP[i][j][1];
				
				//まだ小さいことが確定していない遷移
				if(k==0){
					if(now==0)
						DP[i-1][j][0] += DP[i][j][0];
					else
						DP[i-1][j][1] += DP[i][j][0];
				}
				else{
					if(k<now)
						DP[i-1][j+1][1] += DP[i][j][0];
					else if(k==now)
						DP[i-1][j+1][0] += DP[i][j][0];
				}

			}
		}
	}
	ll ans=0;
	cout<<DP[0][K][0]+DP[0][K][1]<<endl;
	return 0;
}