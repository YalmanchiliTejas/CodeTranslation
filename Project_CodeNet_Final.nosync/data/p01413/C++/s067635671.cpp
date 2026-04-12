#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long ll;
ll knapsack[1<<7][10005];
ll dp[8][1<<8], tsp[1<<8], profit[1<<8];
ll total[10005];
int value[7], weight[7];
int cn[8], cp[8][8], cv[8][8], cx[8], cy[8];


int main()
{
	int N,M,W,T;
	while(cin >> N >> M >> W >> T) {
		map<string, int> dic;
		for(int i=0; i<M; i++) {
			string s;
			int v,p;
			cin >> s >> v >> p;
			dic[s] = i;

			weight[dic[s]] = v;
			value[dic[s]] = p;
		}

		cn[0] = cx[0] = cy[0] = 0;
		for(int i=1; i<=N; i++) {
			cin >> cn[i] >> cx[i] >> cy[i];

			for(int j=0; j<cn[i]; j++) {
				string s;
				int v;
				cin >> s >> v;
				cv[i][j] = max(0, value[dic[s]] - v);
				cp[i][j] = dic[s];
			}
		}

		memset(profit, 0, sizeof(profit));
		memset(knapsack, -1, sizeof(knapsack));
		for(int i=0; i<(1<<N); i++) {
			knapsack[i][0] = 0;
			for(int j=1; j<=N; j++) {
				if(!(i >> (j-1) & 1)) continue; 
				for(int k=0; k<cn[j]; k++) {
					int id = cp[j][k];
					for(int l=0; l<=W - weight[id]; l++) {
						if(knapsack[i][l] == -1) continue;
						knapsack[i][l + weight[id]] = max(knapsack[i][l + weight[id]], knapsack[i][l] + cv[j][k]);
						profit[i<<1] = max(profit[i<<1], knapsack[i][l + weight[id]]);
					}
				}
			}
		}

		N++;
		for(int j=0; j<N; j++)
		for(int i=0; i<(1<<N); i++) {
			dp[j][i] = (1<<28);
			tsp[i] = (1<<28);
		}

		tsp[0] = tsp[1] = 0;
		for(int i=0; i<N; i++) {
			dp[i][1<<i] = abs(cx[i]) + abs(cy[i]);
		}

		for(int i=1; i<(1<<N); i++) {
			for(int j=0; j<N; j++) {
				for(int k=0; k<N; k++) {
					dp[k][i | (1<<k)] = min(dp[k][i | (1<<k)], dp[j][i] + abs(cx[j]-cx[k]) + abs(cy[j]-cy[k]));
					tsp[i | (1<<k) ] = min(tsp[i | (1<<k) ], dp[k][i] + (ll)abs(cx[k]) + (ll)abs(cy[k]));
				}
			}
		}


		memset(total, -1, sizeof(total));
		total[0] = 0;
		for(int i=0; i<(1<<N); i++) {
			for(int j=0; j<=T; j++) {
				if(j + tsp[i] > T) break;
				if(total[j] == -1) continue;
				total[j+tsp[i]] = max(total[j+tsp[i]], total[j] + profit[i]);
			}
		}

		ll res = 0;
		for(int i=0; i<=T; i++)
			res = max(res, total[i]);

		cout << res << endl;
	}
}