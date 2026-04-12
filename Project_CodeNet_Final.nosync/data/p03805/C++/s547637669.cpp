#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int INF = 1000000007;

int n, m;
bool flag[50];
int G[50][50];
int cnt;

int main(void){
 cin>>n>>m;

	int a[50] ={0}, b[50]={0};
	for(int i=0;i<m;i++){
		cin>>a[i]>>b[i];
		a[i]--; b[i]--;
		G[a[i]][b[i]] = 1;
		G[b[i]][a[i]] = 1;
	}

	int ans=0;
	vector<int> v(n-1);
	iota(v.begin(), v.end(), 1);
	do {
		bool can = G[0][v[0]];
		for(int i=0;i<n-2;i++) {
			can &= G[v[i]][v[i + 1]]; // can = (can) && G[v[i]][v[i + 1]];
		}
		if(can) ans++;

	} while( next_permutation(v.begin(), v.end()));

	cout<< ans <<endl;

	return 0;
}