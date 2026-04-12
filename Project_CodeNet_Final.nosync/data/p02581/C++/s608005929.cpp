#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;
const int MIN = -100000;

int n, a[3 * MAXN], shift, mx, dp[MAXN][MAXN], r[MAXN], c[MAXN];

struct todo{
	int i, j, val;
	todo(int i, int j, int val): i(i), j(j), val(val){}
};

void upd(int i, int j, int val){
	dp[i][j] = max(dp[i][j], val - shift);
	r[i] = max(r[i], dp[i][j]);
	c[j] = max(c[j], dp[i][j]);
	mx = max(mx, dp[i][j] + shift);
}

vector <todo> v;
void add_todo(int i, int j, int val){
	v.push_back(todo(i, j, val));
}
void fix(){
	for(todo d : v)
		upd(d.i, d.j, d.val);
	v.clear();
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < 3 * n; i++){
		scanf("%d", &a[i]);
		a[i]--;
	}
	
	shift = 0, mx = 0;
	for(int i = 0; i < n; i++){
		r[i] = MIN;
		c[i] = MIN;
	}
	for(int i = 0; i < n; i++)
	for(int j = 0; j < n; j++){
		dp[i][j] = MIN;
	}
	
	upd(a[0], a[1], 0);
	upd(a[1], a[0], 0);
	
	/*
	cout << "--------------" << endl;
	cout << "Initial ::: " << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cout << dp[i][j] + shift << ' ';
		cout << endl;
	}
	cout << "--------------" << endl;*/
	
	for(int k = 0; k < n - 1; k++){
		for(int i = 0; i < 3; i++)
		for(int j = i + 1; j < 3; j++){
			int x = a[2 + 3 * k + i], y = a[2 + 3 * k + j];
			int z = a[2 + 3 * k] ^ a[3 + 3 * k] ^ a[4 + 3 * k] ^ x ^ y;
			int rmx = max(mx, dp[z][z] + shift + 1);
			
			add_todo(x, y, rmx);
			add_todo(y, x, rmx);
		}
		for(int i = 0; i < 3; i++){
			int x = a[2 + 3 * k + i];
			int y = a[2 + 3 * k + (i + 1) % 3];
			int z = a[2 + 3 * k + (i + 2) % 3];
			
			for(int j = 0; j < n; j++){
				int cmx = max(c[j] + shift, (y == z ? dp[y][j] + shift + 1 : MIN));
				add_todo(x, j, cmx);
				
				int rmx = max(r[j] + shift, (y == z ? dp[j][y] + shift + 1 : MIN));
				add_todo(j, x, rmx);
			}
		}
		
		if(a[2 + 3 * k] == a[3 + 3 * k] && a[3 + 3 * k] == a[4 + 3 * k]){
			shift++;
			mx++;
		}
		fix();
		/*
		cout << "--------------" << endl;
		cout << 2 + 3 * k << " ::: " << endl;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cout << dp[i][j] + shift << ' ';
			cout << endl;
		}
		cout << "--------------" << endl;*/
	}
	
	mx = max(mx, dp[a[3 * n - 1]][a[3 * n - 1]] + shift + 1);
	printf("%d\n", mx);
		
	return 0;
}
