#include<bits/stdc++.h>
#define st first
#define nd second

using ll = long long ;
using ull = unsigned long long;
using namespace std;
using pii = pair<int,int>;
const int N = 505;
const int lim = 64;
stack<int> sRC[2][64];
std::vector<int> vRC[2];
int val[2][N][64], avail[2][N][64];
int s[2][N], have[2][64];
ull ans[N][N] = {0};
ull raw[2][N];
void checker(int n){
	for(int i = 1; i <= n; i++){
		ull val = ans[i][1];
		for(int j = 1; j <= n; j++){
			if(s[0][i] == 0) val &= ans[i][j];
			else val |= ans[i][j];
		}
		if(val != raw[0][i]) {
			printf("at row %d: expect %llu found %llu\nbit(s) different at: ", i, raw[0][i], val);
			for(int j = 0; j < 64; j++){
				if(((1LL << j) & val) != ((1LL << j) & raw[0][i])) printf("%d(%d, %d) ", j,((1LL << j) & val) > 0, ((1LL << j) & raw[0][i]) > 0);
				
			}
			printf("\n");
		}

	}
	for(int i = 1; i <= n; i++){
		ull val = ans[1][i];
		for(int j = 1; j <= n; j++){
			if(s[1][i] == 0) val &= ans[j][i];
			else val |= ans[j][i];
		}
		if(val != raw[1][i]){ 
			printf("at column %d: expect %llu found %llu\nbit(s) diffent at: ", i, raw[1][i], val);
			for(int j = 0; j < 64; j++){
				if(((1LL << j) & val) != ((1LL << j) & raw[1][i])) printf("%d(%d, %d) ", j,((1LL << j) & val) > 0, ((1LL << j) & raw[1][i]) > 0);
				
			}
			printf("\n");
		}
	}
}
int main(){
	int n, k = 5;
	ull x;
	scanf("%d", &n);	
	for(int j = 0; j < 2; j++){
		for(int i = 1;  i <= n; i++){
			scanf("%d", &s[j][i]);
			//printf("at %d %d: %d\n", j, i, s[j][i]);
		}
	}	

	for(int bi = 0; bi < 2; bi++){
		for(int i = 1; i <= n; i++){
			scanf("%llu", &x);
			raw[bi][i] = x;
			for(int j = 0; j < 64; j++){
				val[bi][i][j] = x % 2;
				x >>= 1;
			}
			//printf("at %d %d\n", bi, i);
		}
	}
	for(int bi = 0 ; bi < 2; bi++){
		for(int i = 1; i <= n; i++){
			if(s[bi][i] == 0){					
				vRC[bi].push_back(i);
				if(bi == 0){
					for(int j = 1; j <= n; j++){
						ans[i][j] = raw[bi][i];
					}
					for(int ii = 0; ii < 64; ii++){
						avail[bi][i][ii] = (val[bi][i][ii] == 0 ? n - 1 : 0); 
					}
				}
				else{
					for(int ii = 0; ii < 64; ii++) 
						avail[bi][i][ii] = (val[bi][i][ii] == 0 ? n - 1: 0);
					for(int j = 1; j <= n; j++){
						ans[j][i] = raw[bi][i] | ans[j][i];
						if(s[0][j] == 1) continue;
						for(int ii = 0; ii < 64; ii++){
							if((ans[j][i] & (1LL << ii)) == 0) continue;
							if(val[0][j][ii] == 0) {
								avail[0][j][ii]--;
								if(avail[0][j][ii] < 0){
									return !printf("-1");
								}
							}
							else if(val[1][i][ii] == 0){
								avail[1][i][ii]--;
								if(avail[1][i][ii] < 0){
									return !printf("-1");
								}
							}
						}
					}
				} 
			}

		}
	}	
	for(int bi = 0; bi < 2; bi++){
		for(int i = 1;  i <= n; i++){
			if(s[bi][i] == 1){
				ull prod = 0LL;
				for(int j = 1; j <= n; j++){
					if(bi == 0) prod |= ans[i][j];
					else prod |= ans[j][i];
				}
				for(int j = 0; j < 64; j++){
					if(val[bi][i][j] == 0 && ((prod & (1LL << j)) != 0)) return !printf("-1");
					if(val[bi][i][j] == 0) continue;					
					if((prod & (1LL << j)) == 0) sRC[bi][j].push(i);
					else have[bi][j] = i;
				}
			}
		}
	}
	for(int i = 0; i < 64; i++){
		if(!sRC[0][i].empty() && !sRC[1][i].empty()){
			//printf("at %d\n", i);
			int iR = sRC[0][i].top(), iC = sRC[1][i].top();
			while(!sRC[0][i].empty()){
				int cur  = sRC[0][i].top();
				sRC[0][i].pop();
				ans[cur][iC] |= ((ull)1 << i);
			}
			sRC[1][i].pop();
			while(!sRC[1][i].empty()){
				int cur = sRC[1][i].top();
				sRC[1][i].pop();
				ans[iR][cur] |= ((ull)1 << i);
			}
		} 
	}
	
	for(int bi = 0; bi < 2; bi++){
		for(int i = 0; i < 64; i++){
			if(sRC[bi][i].empty()) continue;
			if(have[1-bi][i] != 0){
				int u = have[1-bi][i];
				while(!sRC[bi][i].empty()){
					int v = sRC[bi][i].top();
					sRC[bi][i].pop();
					if(bi == 0) ans[v][u] |= (1LL << i);
					else ans[u][v] |= (1LL << i);
				}
				continue;
			}
			for(auto it: vRC[1-bi]){
				while(avail[1-bi][it][i] > 0){
					int u = sRC[bi][i].top();
					sRC[bi][i].pop();
					if(bi == 0){
						ans[u][it] |= (1LL << i);
					}
					else  ans[it][u] |= (1LL << i);
					avail[1-bi][it][i]--;
					if(sRC[bi][i].empty())  break;
				}
				if(sRC[bi][i].empty()) break;
			}
			if(!sRC[bi][i].empty()) return !printf("-1");
			
		}
	}
	//#define D
	#ifndef D
	for(int i = 1; i <= n;i++){
		for(int j = 1; j <= n; j++){
			printf("%llu ",ans[i][j]);
		}
		printf("\n");
	}
	#else
	checker(n);
	#endif
}