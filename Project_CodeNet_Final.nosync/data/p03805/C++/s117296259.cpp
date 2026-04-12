#include <iostream>
using namespace std;

int N, M, now;
int ab[8][8] = {};
int visit[8]={};
int answer = 0;




// Judge that we have already visited all node.
bool all_visit(){
	bool ans = true;
	for(int j=0; j<N; j++){
		ans *= (visit[j] == 1);
	}
	return ans;
}


int num_path(int start){
	if(all_visit()){
		answer++;
	}

	for(int i=0; i<N; i++){
		if(visit[i] == 0 && ab[start][i] == 1){
			visit[i] = 1;
			num_path(i);
			visit[i] = 0;
		}
	}
	return 0;
}

int solve(){
	visit[0] = 1;
	num_path(0);
	cout << answer << endl;
	return 0;
}

int main(){
	int a,b;
	cin >> N >> M;
	for(int i=0; i<M;i++){
		cin >> a >> b;
		ab[a-1][b-1] = 1;
		ab[b-1][a-1] = 1;
	}
	solve();
	return 0;
}