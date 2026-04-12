#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <list>
#include <stack>

using namespace std;

typedef pair<long long int, long long int> P;

long long int INF = 1e18;
long long int MOD = 1e9 + 7;

int main(){
	
	int N, M;
	cin >> N >> M;
	
	bool E[10][10] = {};
	
	for(int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		E[a][b] = true;
		E[b][a] = true;
	}
	
	int num[10] = {2, 3, 4, 5, 6, 7, 8};
	int ans = 0;
	
	do{
		bool flag = E[1][num[0]];
		for(int i = 0; i < N - 2; i++){
			flag = (flag && E[num[i]][num[i + 1]]);
		}
		if(flag){
			ans += 1;
		}
	}while(next_permutation(num, num + (N - 1)));
	
	cout << ans << endl;
	
	return 0;
}
