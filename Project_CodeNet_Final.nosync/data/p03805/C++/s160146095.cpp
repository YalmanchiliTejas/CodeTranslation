#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n, m, a, b;
	cin >> n >> m;
	
	//vector < int > graph[n];
	int graph[n][n]; //graphの記憶
	int cities[n]; //next_permutation用
	for(int i =0; i< n; i++){
		cities[i] = i;
		for(int j = 0; j < n; j++){graph[i][j] = 0;}
	}
	
	for(int i = 0; i< m; i++){
		cin >> a >> b;
		graph[a-1][b-1] = 1;
		graph[b-1][a-1] = 1;
	}
	
	int count = 0;
	do{
		count ++;
		//for(int i = 0; i< n; i++){cout << cities[i];}
		//cout << " :check the root" << endl;
		for(int i = 0; i< n-1; i++){
			//cout << cities[i] << ", "<<cities[i+1] << endl;
			if(graph[cities[i]][cities[i+1]] == 0){
				//cout << "break"<< endl;
				count --; break;
			}
			
		}
	}while(next_permutation(cities+1, cities+n)); 
	//始点が1(cities, graphのインデックス0)固定なので, cities[1] ~ cities[n-1]までを変更
	//この覚え方間違えそうだな・・・
	
	cout << count << endl;
	return 0;


}