#include <bits/stdc++.h>
using namespace std;

enum{U = 0, D = 1, N = 2, E = 3, W = 4, S = 5};
vector<int> d{1, 6, 5, 3, 4, 2};
void rotate(int a, int b, int c, int dd){
	int t = d[a];
	d[a] = d[b];
	d[b] = d[c];
	d[c] = d[dd];
	d[dd] = t;
}

int main(){
	int n;
	while(cin >> n, n){
		int sum = 0;
		d = {1, 6, 5, 3, 4, 2};
		for(int i=0; i < n; i++){
			string s; cin >> s;
			if(s[0] == 'N') rotate(U, S, D, N);
			else if(s[0] == 'E') rotate(E, U, W, D);
			else if(s[0] == 'W') rotate(D, W, U, E);
			else if(s[0] == 'S') rotate(S, U, N, D);
			else if(s[0] == 'R') rotate(S, E, N, W);
			else if(s[0] == 'L') rotate(S, W, N, E);
			sum += d[U];
		}
		cout << sum+1 << endl;
	}
}