#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using ll = unsigned long long int;
const int INF = (1<<30);
const ll INFLL = (1ll<<60);
const ll MOD = (ll)(1e9+7);

#define l_ength size

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	a = (a<MOD)?a:(a-MOD);
	b = (b<MOD)?b:(b-MOD);
	a += b;
	a = (a<MOD)?a:(a-MOD);
}

int s[555],t[555],u[555][64],v[555][64];
ll tmp[555][555],ans[555][555];
bool f[555][555],row[555][2],col[555][2];
std::vector<int> x,y;

int main(void){
	int n,i,j,k,nya;
	ll a;
	bool flag = true;
	std::cin >> n;
	for(i=0; i<n; ++i){
		std::cin >> s[i];
	}
	for(i=0; i<n; ++i){
		std::cin >> t[i];
	}
	for(i=0; i<n; ++i){
		std::cin >> a;
		for(k=0; k<64; ++k){
			u[i][k] = a%2; a/=2;
		}
	}
	for(i=0; i<n; ++i){
		std::cin >> a;
		for(k=0; k<64; ++k){
			v[i][k] = a%2; a/=2;
		}
	}
	for(k=0; k<64; ++k){
		std::fill(f[0],f[555],false);
		std::fill(row[0],row[555],false);
		std::fill(col[0],col[555],false);
		for(i=0; i<n; ++i){
			if(s[i]==0&&u[i][k]==1){
				for(j=0; j<n; ++j){
					tmp[i][j] = 1;
					f[i][j] = true;
					row[i][1] = true;
					col[j][1] = true;
				}
			}else if(s[i]==1&&u[i][k]==0){
				for(j=0; j<n; ++j){
					tmp[i][j] = 0;
					f[i][j] = true;
					row[i][0] = true;
					col[j][0] = true;
				}
			}else{
				x.push_back(i);
			}
		}
		for(j=0; j<n; ++j){
			if(t[j]==0&&v[j][k]==1){
				for(i=0; i<n; ++i){
					tmp[i][j] = 1;
					f[i][j] = true;
					row[i][1] = true;
					col[j][1] = true;
				}
			}else if(t[j]==1&&v[j][k]==0){
				for(i=0; i<n; ++i){
					tmp[i][j] = 0;
					f[i][j] = true;
					row[i][0] = true;
					col[j][0] = true;
				}
			}else{
				y.push_back(j);
			}
		}
		if(x.l_ength()==1){
			i = 0;
			for(j=0; j<y.l_ength(); ++j){
				if((t[y[j]]&v[y[j]][k])&&(!col[y[j]][1])){
					tmp[x[i]][y[j]] = 1;
					f[x[i]][y[j]] = true;
					row[x[i]][1] = true;
					col[y[j]][1] = true;
				}else if((!(t[y[j]]&v[y[j]][k])) && (!col[y[j]][0])){
					tmp[x[i]][y[j]] = 0;
					f[x[i]][y[j]] = true;
					row[x[i]][0] = true;
					col[y[j]][0] = true;
				}
			}
			for(j=0; j<y.l_ength(); ++j){
				if(f[x[i]][y[j]]){
					continue;
				}
				if((s[x[i]]&u[x[i]][k])){
					tmp[x[i]][y[j]] = 1;
					f[x[i]][y[j]] = true;
					row[x[i]][1] = true;
					col[y[j]][1] = true;
				}else if((!(s[x[i]]&u[x[i]][k]))){
					tmp[x[i]][y[j]] = 0;
					f[x[i]][y[j]] = true;
					row[x[i]][0] = true;
					col[y[j]][0] = true;
				}
			}
		}else if(y.l_ength()==1){
			j = 0;
			for(i=0; i<x.l_ength(); ++i){
				if((s[x[i]]&u[x[i]][k])&&(!row[x[i]][1])){
					tmp[x[i]][y[j]] = 1;
					f[x[i]][y[j]] = true;
					row[x[i]][1] = true;
					col[y[j]][1] = true;
				}else if((!(s[x[i]]&u[x[i]][k])) && (!row[x[i]][0])){
					tmp[x[i]][y[j]] = 0;
					f[x[i]][y[j]] = true;
					row[x[i]][0] = true;
					col[y[j]][0] = true;
				}
			}
			for(i=0; i<x.l_ength(); ++i){
				if(f[x[i]][y[j]]){
					continue;
				}
				if((t[y[j]]&v[y[j]][k])){
					tmp[x[i]][y[j]] = 1;
					f[x[i]][y[j]] = true;
					row[x[i]][1] = true;
					col[y[j]][1] = true;
				}else if((!(t[y[j]]&v[y[j]][k]))){
					tmp[x[i]][y[j]] = 0;
					f[x[i]][y[j]] = true;
					row[x[i]][0] = true;
					col[y[j]][0] = true;
				}
			}
		}else{
			for(i=0; i<x.l_ength(); ++i){
				for(j=0; j<y.l_ength(); ++j){
					tmp[x[i]][y[j]] = (i+j)%2;
					f[x[i]][y[j]] = true;
					row[x[i]][(i+j)%2] = true;
					col[y[j]][(i+j)%2] = true;
				}
			}
		}
		/*
		for(i=0; i<n; ++i){
			for(j=0; j<n; ++j){
				printf("%d ",tmp[i][j]);
			}
			printf("\n");
		}
		*/
		for(i=0; i<n; ++i){
			if(s[i]){
				nya = 0;
			}else{
				nya = 1;
			}
			for(j=0; j<n; ++j){
				if(s[i]){
					nya |= tmp[i][j];
				}else{
					nya &= tmp[i][j];
				}
			}
			if(nya!=u[i][k]){
				std::cout << "-1" << std::endl;
				return 0;
			}
		}
		for(j=0; j<n; ++j){
			if(t[j]){
				nya = 0;
			}else{
				nya = 1;
			}
			for(i=0; i<n; ++i){
				if(t[j]){
					nya |= tmp[i][j];
				}else{
					nya &= tmp[i][j];
				}
			}
			if(nya!=v[j][k]){
				std::cout << "-1" << std::endl;
				return 0;
			}
		}
		for(i=0; i<n; ++i){
			for(j=0; j<n; ++j){
				ans[i][j] += (tmp[i][j]<<k);
			}
		}
		x.clear(); y.clear();
	}
	for(i=0; i<n; ++i){
		for(j=0; j<n; ++j){
			std::cout << (j?" ":"") << ans[i][j];
		}
		std::cout << std::endl;
	}
	return 0;
}
