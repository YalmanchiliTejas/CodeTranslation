#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define SIZE 1005

struct LOC{
	LOC(int arg_row,int arg_col){
		row = arg_row;
		col = arg_col;
	}
	bool operator<(const struct LOC &arg)const{

		if(row != arg.row){

			return row < arg.row;
		}else{
			return col < arg.col;
		}
	}
	bool operator==(const struct LOC &arg) const{

		return row == arg.row && col == arg.col;
	}
	int row,col;
};

int H,W;
int min_row[SIZE],max_row[SIZE],min_col[SIZE],max_col[SIZE];
char table[SIZE][SIZE];
vector<LOC> V;

int main(){

	scanf("%d %d",&H,&W);

	for(int row = 0; row < H; row++){

		min_col[row] = BIG_NUM;
		max_col[row] = -BIG_NUM;
	}

	for(int col = 0; col < W; col++){

		min_row[col] = BIG_NUM;
		max_row[col] = -BIG_NUM;
	}

	for(int row = 0; row < H; row++){

		scanf("%s",table[row]);

		for(int col = 0; col < W; col++){

			if(table[row][col] == 'B'){

				min_col[row] = min(min_col[row],col);
				max_col[row] = max(max_col[row],col);

				min_row[col] = min(min_row[col],row);
				max_row[col] = max(max_row[col],row);
			}
		}
	}

	for(int row = 0; row < H; row++){

		if(abs(min_col[row]) != BIG_NUM){

			V.push_back(LOC(row,min_col[row]));
		}
		if(abs(max_col[row]) != BIG_NUM){

			V.push_back(LOC(row,max_col[row]));
		}
	}

	for(int col = 0; col < W; col++){

		if(abs(min_row[col]) != BIG_NUM){

			V.push_back(LOC(min_row[col],col));
		}
		if(abs(max_row[col]) != BIG_NUM){

			V.push_back(LOC(max_row[col],col));
		}
	}

	sort(V.begin(),V.end());
	V.erase(unique(V.begin(),V.end()),V.end());

	int ans = 0;

	for(int i = 0; i < V.size()-1; i++){
		for(int k = i+1; k < V.size(); k++){

			ans = max(ans,abs(V[i].row-V[k].row)+abs(V[i].col-V[k].col));
		}
	}

	printf("%d\n",ans);

	return 0;
}

