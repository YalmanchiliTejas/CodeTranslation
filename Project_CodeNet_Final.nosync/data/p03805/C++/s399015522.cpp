#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> roads;
vector<bool> came;

int move(int now, int moved){
	if(moved == N - 1){
		return 1;
	}else{
		int ans = 0;
		came[now] = true;
		for(int i = 0; i < roads[now].size(); i++){
			if(!came[roads[now][i]]){
				ans += move(roads[now][i], moved + 1);
			}
		}
		came[now] = false;
		return ans;
	}
}
 
int main(){
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		roads.push_back({});
		came.push_back(false);
	}
	for(int i = 0; i < M; i++){
		int start, goal;
		cin >> start >> goal;
		roads[start - 1].push_back(goal - 1);
		roads[goal - 1].push_back(start - 1);
	}
	cout << move(0, 0) << endl;
}