#include <iostream>
#include <vector>
using namespace std;

int N,count = 0;
bool judge = true;
vector<vector<int>> v(100010);
int visited[100010] = {0},col[100010] = {0};


bool dfs(int n){
	visited[n] = 1;
	bool j = true;
	if(n!=1 && v[n].size()==1) return true;
	for(int i=0;i<v[n].size();i++){
		int s = v[n][i];
		if(visited[s]==0 && dfs(s)){
			if(col[n]==0){
				col[n] = 1;
				count++;
				j = false;
			}else judge = false;
		}
	}
	return j;
}


int main(){
	cin >> N;
	int a,b;
	for(int i=0;i<N-1;i++){
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	if(N%2==1){
		cout << "First" << endl;
		return 0;
	}
	dfs(1);
/*	for(int i=1;i<=N;i++){
		cout << col[i] << (i!=N? " ":"\n");
	}
*/	cout << (!judge? "First":"Second") << endl;
}