#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int n,m,num[8];
	bool edge[8][8] = {};
	cin >> n >> m;
	for(int i = 0;i < m;i++){
		int a,b;
		cin >> a >> b; a--; b--;
		edge[a][b] = true;
		edge[b][a] = true;
	}
	for(int i = 0;i < n;i++) num[i] = i;
	int res = 0;
	do{
		bool flag = true;
		for(int i = 0;i < n - 1;i++){
			if(!edge[num[i]][num[i + 1]]) flag = false;
		}
		if(flag) res++;
	}while(next_permutation(num + 1,num + n));
	cout << res << endl;
	return 0;
}