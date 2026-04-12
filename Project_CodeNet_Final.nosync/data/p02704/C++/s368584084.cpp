#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 505

int N;
ull POW[64];
ull S[2][SIZE],U[2][SIZE];
ull ans[SIZE][SIZE],BIT[2][SIZE],work[SIZE][SIZE];

void transPose(){

	for(int row = 0; row < N; row++){
		for(int col = 0; col < row; col++){

			swap(work[row][col],work[col][row]);
		}
	}
}

bool solve(){

	for(int row = 0; row < N; row++){
		for(int col = 0; col < N; col++){

			work[row][col] = -1;
		}
	}

	for(int loop = 0; loop < 2; loop++){
		for(int row = 0; row < N; row++){

			ull tmp = BIT[loop][row];
			if(S[loop][row] != tmp){ //論理積が1,または論理和が0

				for(int col = 0; col < N; col++){

					if(work[row][col] == (1-tmp)){

						return false;
					}
					work[row][col] = tmp;
				}
			}
		}
		transPose();
	}

	for(int a = 0; a < 2; a++){
		for(int loop = 0; loop < 2; loop++){
			for(int row = 0; row < N; row++){
				ull tmp = BIT[loop][row];
				if(S[loop][row] == tmp){ //論理積の0,論理和の1:少なくとも1つ行の中にあれば良い
					vector<int> p;
					bool FLG = false;
					for(int col = 0; col < N; col++){
						if(work[row][col] == -1){ //未確定列

							p.push_back(col);
						}
						if(work[row][col] == tmp){

							FLG = true;
						}
					}
					if(FLG)continue; //条件を既に満たしている
					if(p.size() == 0)return false;
					if(p.size() == 1){

						work[row][p[0]] = tmp;
					}
					//p.size() >= 2:保留
				}
			}
			transPose();
		}
	}

	vector<int> R,C;

	for(int row = 0; row < N; row++){
		for(int col = 0; col < N; col++){
			if(work[row][col] == -1){
				R.push_back(row);
				break;
			}
		}
	}
	for(int col = 0; col < N; col++){
		for(int row = 0; row < N; row++){
			if(work[row][col] == -1){

				C.push_back(col);
				break;
			}
		}
	}

	for(int i = 0; i < R.size(); i++){
		for(int k = 0; k < C.size(); k++){

			work[R[i]][C[k]] = (i+k)%2;
		}
	}

	return true;
}


int main(){

	POW[0] = 1;
	for(int i = 1; i <= 63; i++){

		POW[i] = POW[i-1]*2;
	}

	scanf("%d",&N);

	for(int i = 0; i < N; i++){

		cin >> S[0][i];
	}
	for(int i = 0; i < N; i++){

		cin >> S[1][i];
	}
	for(int i = 0; i < N; i++){

		cin >> U[0][i];
	}
	for(int i = 0; i < N; i++){

		cin >> U[1][i];
	}

	for(int row = 0; row < N; row++){
		for(int col = 0; col < N; col++){

			ans[row][col] = 0;
		}
	}

	for(int i = 63; i >= 0; i--){ //桁のループ
		for(int loop = 0; loop < 2; loop++){ //行、列のループ
			for(int k = 0; k < N; k++){ //行または列のループ
				if(U[loop][k] & POW[i]){

					BIT[loop][k] = 1;

				}else{

					BIT[loop][k] = 0;
				}
			}
		}
		if(!solve()){

			printf("-1\n");
			return 0;
		}
		for(int row = 0; row < N; row++){
			for(int col = 0; col < N; col++){

				ans[row][col] += POW[i]*work[row][col];
			}
		}
	}

	for(int row = 0; row < N; row++){

		printf("%llu",ans[row][0]);
		for(int col = 1; col < N; col++){

			printf(" %llu",ans[row][col]);
		}
		printf("\n");
	}

	return 0;
}
