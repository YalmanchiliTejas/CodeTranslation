#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <climits>
#include <bitset>
#include <list>
#include <map>
#include <set>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
	int n, m;
	cin >> n >> m;
	int mat[n][n];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			mat[i][j]=0;
		}
	}
	for(int i=0; i<m; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		mat[a][b]=1;
		mat[b][a]=1;
	}

	vector<int> v;
	for(int i=0; i<n; i++) v.push_back(i);
	int ans=0;
	while(v[0]==0){
		bool b=true;
		for(int i=1; i<n; i++){
			if(mat[v[i-1]][v[i]]==0) b=false;
		}
		if(b) ans++;
		next_permutation(v.begin(), v.end());
	}
	cout << ans << endl;
	return 0;
}