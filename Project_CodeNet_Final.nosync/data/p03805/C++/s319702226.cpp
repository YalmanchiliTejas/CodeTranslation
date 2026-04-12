//ABC054 C
#include <bits/stdc++.h>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define ll long long
#define INF 999999999
#define MOD 1000000007

using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

int iy[]={0, 0, 1, -1};
int ix[]={1, -1, 0, 0};

int n2, m, a, b, ans; 
bool t[9][9];

bool used[8];
int perm[8];
//0からn-1
void permutation1(int pos, int n){
	if(pos == n){
		bool flag = 1;
		for(int i=1;i<n;i++){
			if(!t[perm[i]][perm[i-1]]) flag = 0;
		}
		if(flag) ans++;
		//permに対する操作
		return ;
	}

	//permのpos番目を0からn-1のどれにするか
	for(int i = 1; i < n; i++){
		if(!used[i]){
			perm[pos] = i;
			used[i] = true; //iのフラグをtrueに
			permutation1(pos + 1, n);
			used[i] = false; //フラグを戻す
		}
	}
	return ;
}


int main(){
	cin >> n2 >> m;
	for(int i=0;i<m;i++){
		cin >> a >> b;
		t[a-1][b-1] = 1;
		t[b-1][a-1] = 1;
	}
	permutation1(1, n2);
	cout << ans << endl;
	return 0;
}