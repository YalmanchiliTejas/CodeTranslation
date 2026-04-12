
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<cstring>
using namespace std;
#define REP(i, a,b) for(i=a;i<b;i++) 
#define output(x) cout<<x<<endl;

int par[100001];

void init(int n) {
	for (int i = 0; i < n; i++) {
		par[i] = i;
	}
}
//木の根を求める
int root(int x) {
	if (par[x] == x)
		return x;
	else {
		return par[x] = root(par[x]);
	}
}
//find
bool same(int x, int y) {
	return root(x) == root(y);

}
//union
void unite(int x, int y) {
	x = root(x);
	y = root(y);
	if (x == y) return;
	par[x] = y;
}

int main()
{
	long long int i, j, k, l, m, n, sum, flag;
	sum = 0;
	flag = 0;
	char S[6];
	cin >> S;
	for (i = 0; i < strlen(S) - 1; i++) {
		if (S[i] == 'A'&&S[i + 1] == 'C') {
			flag = 1;
			break;
		}
	}
	if (flag) {
		output("Yes");
	}
	else
		output("No");


	return 0;
}

