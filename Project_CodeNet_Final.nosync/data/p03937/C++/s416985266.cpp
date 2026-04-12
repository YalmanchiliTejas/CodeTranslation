/*
Owner: dxxrk
Problem: Shik and Stone
Date: 21/11/2019
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 3;
const int M = 1e6 + 7;
const long long MOD = 1e9 + 7;
const long long INF = 1e18 + 9;
const int SM = 1e3 + 8;
const int logN = 20, BL = 400;
const double EPS = 3e-16;

int h, w;
char g[SM][SM]; 

bool isPossible(int x, int y){
	return x < h && y < w;
}

int main(){
//	freopen("ex.in", "r", stdin);
//	freopen("ex.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> h >> w;
	
	int all = 0;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cin >> g[i][j];
			all += (g[i][j] == '#');
		}
	}
	
	int counter = 0;	
	queue<pair<int, int>> q;
	q.push({0, 0});
	while(!q.empty()){
		counter++;
		pair<int, int> v = q.front();
		int x = v.first, y = v.second;
		q.pop();
		
		if(x == h - 1 && y == w - 1) break;
		if(isPossible(x + 1, y)){
			q.push({x + 1, y});
		}
		else {
			q.push({x, y + 1});
		}
	}
	
	if(all == counter){
		cout << "Possible";
	}
	else {
		cout << "Impossible";
	}
	return 0;
}
