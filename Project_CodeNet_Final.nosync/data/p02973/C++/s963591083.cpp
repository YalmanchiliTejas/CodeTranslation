// kyopro.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<map>
#include<algorithm>
#include<set>
#include<queue>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
using namespace std;
#define ll long long int
#define rep(N) for(ll i=0;i<N;i++)
#define For(i,N) for(ll i=0;i<N;i++)
int main()
{
	ll N;
	cin >> N;
	vector<ll>A(N + 1);
	rep(N) {
		cin >> A[i + 1];
	}
	ll c = 0;
	vector<ll>atai;
	vector<ll>DP(N + 1);
	DP[0] = 0;
	DP[1] = 1;
	atai.push_back(A[1]);
	
	rep(N-1) {
		if (A[i + 2] > *(--atai.end())) {
			*(--atai.end()) = A[i + 2];
			DP[i + 2] = DP[i + 1];
			
			
		}
		else if (A[i + 2] <= atai[0]) {
		
			DP[i + 2] = DP[i + 1] + 1;
			auto ita = atai.begin();
			atai.insert(ita, A[i + 2]);
			
			
		}
		else {
			DP[i + 2] = DP[i + 1];
			auto ita = lower_bound(atai.begin(),atai.end(),A[i + 2]);
			while (1) {
				if (*ita < A[i + 2]) {
					*ita = A[i + 2];
					break;
				}
				ita--;
			}
			
		}

	}
	cout << DP[N];
}
