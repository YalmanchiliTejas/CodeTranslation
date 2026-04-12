#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define EPS (1e-10)

using namespace std;


vector<int>  dx = {1,-1,0,0};
vector<int>  dy = {0,0,1,-1};

string max_ab(int a, int b) {
	if (a >= b) {
		return "A";
	}else {
		return "B";
	}
}

int main() {
	int A,B,C; cin >> A >> B >> C;
	int X,Y; cin >> X >> Y;
	pair<int, int> AX = make_pair(A,X);
	pair<int, int> BY = make_pair(B,Y);
	string max_AB = max_ab(A,B);
	string max_XY = max_ab(X,Y);
	map<string,pair<int,int>> need;
	need["A"] = AX;
	need["B"] = BY;
	int cost = 0;
	if (A + B >= C * 2) {
		int XY = min(X, Y) * 2;
		cost += XY * C;
		//残りの計算
		if (need[max_XY].first > 2 * C)  {
			cost += 2 * C * (max(X,Y) - min(X,Y));
		}else {
			cost += need[max_XY].first * (max(X,Y) - min(X,Y));
		}
	}else {
		cost += A * X + B * Y;		
	}
	cout << cost << endl;

	return 0;
}
