/*L - Deque*/
#include <bits/stdc++.h>
using namespace std;

using Long = long long;

const Long INF = 4000000000000ll;

vector <Long> arr;
vector <vector <Long> > memo;
Long maxValue(int ini, int fin);

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int tam;

	cin >> tam;

	arr = vector <Long> (tam);
	memo = vector <vector <Long> > (tam, vector <Long> (tam, INF));

	for (int i = 0; i < tam; ++i)
		cin >> arr[i];


	Long ans;

	ans = maxValue(0, tam - 1);

	cout << ans;

	return 0;
}

Long maxValue(int ini, int fin){

	if(ini > fin){
		return 0;
	}

	if(memo[ini][fin] != INF){
		return memo[ini][fin];
	}

	Long ans;

	ans = -maxValue(ini + 1, fin) + arr[ini];
	ans = max(ans, -maxValue(ini, fin - 1) + arr[fin]);

	memo[ini][fin] = ans;
	
	return ans;
}