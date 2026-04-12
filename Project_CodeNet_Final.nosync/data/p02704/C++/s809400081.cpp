#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef unsigned long long ull;

int n;
int s[510];
int t[510]; 
ull u[510];
ull v[510];

ull ans[510][510];

signed main(){
	cin >> n;

	for(int i = 0;i < n;i++) cin >> s[i];
	for(int i = 0;i < n;i++) cin >> t[i];
	for(int i = 0;i < n;i++) cin >> u[i];
	for(int i = 0;i < n;i++) cin >> v[i];

	for(int i = 0;i < n;i++){
		if(s[i] == 0){
			for(int j = 0;j < n;j++){
				ans[i][j] |= u[i];
			}
		}
	}

	for(int j = 0;j < n;j++){
		if(t[j] == 0){
			for(int i = 0;i < n;i++){
				ans[i][j] |= v[j]; 
			}
		}
	}

	ull tate[510];
	for(int i = 0;i < n;i++){
		if(s[i] == 0) tate[i] = ULLONG_MAX;
		else tate[i] = 0;
	}

	ull yoko[510];
	for(int i = 0;i < n;i++){
		if(t[i] == 0) yoko[i] = ULLONG_MAX;
		else yoko[i] = 0;
	}

	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if(s[i] == 0){
				tate[i] &= ans[i][j];
			}else{
				tate[i] |= ans[i][j];  
			}

			if(t[j] == 0){
				yoko[j] &= ans[i][j];
			}else{
				yoko[j] |= ans[i][j];
			}
		}
	}

	for(int i = 0;i < n;i++){
		if(s[i] == 0){
			if(tate[i] != u[i]){
				cout << -1 << endl;
				return 0;
			}
		}else{
			if((tate[i] & (~u[i])) != 0){
				cout << -1 << endl;
				return 0;
			}
		}
	}

	for(int i = 0;i < n;i++){
		if(t[i] == 0){
			if(yoko[i] != v[i]){
				cout << -1 << endl;
				return 0;
			}
		}else{
			if((yoko[i] & (~v[i])) != 0){
				cout << -1 << endl;
				return 0;
			}
		}
	}

	int tocnt[510][510] = {};

	for(int i = 0;i < n;i++){
		if(s[i] == 1){
			for(ull b = 0;b < 64;b++){
				if(u[i] & (1ull << b)){
					for(int j = 0;j < n;j++){
						if(t[j] == 0 || t[j] == 1 && ((v[j] & (1ull << b)) != 0) || ((ans[i][j] & (1ull << b)) != 0)){
							tocnt[i][b]++;
							ans[i][j] |= (1ull << b);
						}  
					}
					if(tocnt[i][b] == 0){
						cout << -1 << endl;
						return 0;
					}
				}
			}
		}
	}

	for(int j = 0;j < n;j++){
		ull tmp = ULLONG_MAX;
		if(t[j] == 0){
			for(int i = 0;i < n;i++){
				tmp &= ans[i][j];
			}
		if(tmp != v[j]){
			for(ull b = 0;b < 64;b++){
				if((tmp & (1ull << b)) != 0 && (v[j] & (1ull << b)) == 0){
					bool f = false;
					for(int i = 0;i < n;i++){
						if(tocnt[i][b] > 1){
							tocnt[i][b]--;
							ans[i][j] ^= (1ull << b);
							f = true;
							break;
						}
					}
					if(!f){
						cout << -1 << endl;
						return 0;
					}
				}
			}
		}
		}
	}

	int yocnt[510][510] = {};

	for(int j = 0;j < n;j++){
		if(t[j] == 1){
			for(ull b = 0;b < 64;b++){
				if(v[j] & (1ull << b)){
					for(int i = 0;i < n;i++){
						if(s[i] == 0 || s[i] == 1 && ((u[i] & (1ull << b)) != 0) || ((ans[i][j] & (1ull << b)) != 0)){
							yocnt[j][b]++;
							ans[i][j] |= (1ull << b);
						}  
					}
					if(yocnt[j][b] == 0){
						cout << -1 << endl;
						return 0;
					}
				}
			}
		}
	}

	for(int i = 0;i < n;i++){
		ull tmp = ULLONG_MAX;
		if(s[i] == 0){
			for(int j = 0;j < n;j++){
				tmp &= ans[i][j];
			}
		if(tmp != u[i]){
			for(ull b = 0;b < 64;b++){
				if((tmp & (1ull << b)) != 0 && (u[i] & (1ull << b)) == 0){
					bool f = false;
					for(int j = 0;j < n;j++){
						if(yocnt[j][b] > 1){
							yocnt[j][b]--;
							ans[i][j] ^= (1ull << b);
							f = true;
							break;
						}
					}
					if(!f){
						cout << -1 << endl;
						return 0;
					}
				}
			}
		}
		}
	}

	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			cout << ans[i][j];
			if(j < n-1){
				cout << " ";
			}else{
				cout << endl;
			}
		}
	}

	return 0;
}
