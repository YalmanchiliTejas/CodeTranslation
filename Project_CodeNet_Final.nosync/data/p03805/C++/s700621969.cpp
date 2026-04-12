#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

#define ll long long
#define pb push_back

int N, M;
vector<pair<int, int>> V;
bool flag[10];
ll ans = 0;

void flagInit(){
	for(int i = 1; i <= N; i ++)flag[i] = false;
}
bool checkAllFlagTrue(){
	for(int i = 1; i <= N; i ++)if(!flag[i])return false;
	return true;
}
void search(int node){
	flag[node] = true;
	if(checkAllFlagTrue()){
		ans ++;
		return;
	}
	for(int i = 1; i <= M; i ++){
		if(V[i].first == node && !flag[V[i].second]){
			search(V[i].second);
			flag[V[i].second] = false;
		}
		if(V[i].second == node && !flag[V[i].first]){
			search(V[i].first);
			flag[V[i].first] = false;
		}
	}
}

int main(){

	cin >> N >> M;
	V.pb(make_pair(0, 0));
	for(int i = 1; i <= M; i ++){
		int a, b;
		cin >> a >> b;
		V.pb(make_pair(a, b));
	}
	flagInit();
	search(1);
	cout << ans << endl;
	
	return 0;
}
