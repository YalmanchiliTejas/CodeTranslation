#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define NUM 1000000

int N;
ll POW[25];
ll dp[1005];
char line[1000][9];

//start_posからnumbytesを、num_bytes文字として見なせるかをチェック
bool check(int start_pos,int num_bytes){

	switch(num_bytes){
	case 1:
		return line[start_pos][0] != '1';
	case 2:
		if(line[start_pos][0] != '0' && line[start_pos][1] != '0' && line[start_pos][2] != '1' &&
				line[start_pos+1][0] != '0' && line[start_pos+1][1] != '1'){
			return true;
		}else{
			return false;
		}
	case 3:
		if(line[start_pos][0] != '0' && line[start_pos][1] != '0' &&
				line[start_pos][2] != '0' && line[start_pos][3] != '1' &&
				line[start_pos+1][0] != '0' && line[start_pos+1][1] != '1' &&
				line[start_pos+2][0] != '0' && line[start_pos+2][1] != '1'){
			return true;
		}else{
			return false;
		}
	case 4:
		if(line[start_pos][0] != '0' && line[start_pos][1] != '0' &&
				line[start_pos][2] != '0' && line[start_pos][3] != '0' && line[start_pos][4] != '1' &&
				line[start_pos+1][0] != '0' && line[start_pos+1][1] != '1' &&
				line[start_pos+2][0] != '0' && line[start_pos+2][1] != '1' &&
				line[start_pos+3][0] != '0' && line[start_pos+3][1] != '1'){
			return true;
		}else{
			return false;
		}
	}
	return false; //must not reach here
}

ll recursive(int start_pos){

	if(dp[start_pos] != -1)return dp[start_pos];

	ll ret = 0,tmp;

	int x_num,y_num;
	bool y_FLG;

	for(int i = 1; i <= 4; i++){
		if(start_pos+i > N)break;

		if(!check(start_pos,i))continue; //start_posからiバイトを、iバイトの文字と見なせないならSKIP

		switch(i){
		case 1:
			x_num = 0;
			for(int k = 1; k <= 7; k++){
				if(line[start_pos][k] == 'x')x_num++;
			}
			tmp = POW[x_num];
			break;
		case 2:
			y_FLG = false;
			y_num = 0;
			for(int k = 3; k <= 6; k++){
				if(line[start_pos][k] == '1'){
					y_FLG = true;
				}else if(line[start_pos][k] == 'x'){
					y_num++;
				}
			}

			x_num = 0;
			if(line[start_pos][7] == 'x')x_num++;
			for(int k = 2; k <= 7; k++){
				if(line[start_pos+1][k] == 'x')x_num++;
			}

			if(y_FLG){ //yの中に1がある

				tmp = POW[x_num]*POW[y_num];

			}else{
				tmp = POW[x_num]*(POW[y_num]-1); //少なくとも1つ1を立てる必要があり
			}
			break;
		case 3:
			/*★複数文字にまたがるyの中で、少なくとも1つ1があれば良いと解釈★*/
			y_FLG = false;
			y_num = 0;
			for(int k = 4; k <= 7; k++){
				if(line[start_pos][k] == '1'){
					y_FLG = true;
				}else if(line[start_pos][k] == 'x'){
					y_num++;
				}
			}
			if(line[start_pos+1][2] == '1'){
				y_FLG = true;
			}else if(line[start_pos+1][2] == 'x'){
				y_num++;
			}

			x_num = 0;
			for(int k = 3; k <= 7; k++){
				if(line[start_pos+1][k] == 'x')x_num++;
			}
			for(int k = 2; k <= 7; k++){
				if(line[start_pos+2][k] == 'x')x_num++;
			}

			if(y_FLG){

				tmp = POW[x_num]*POW[y_num];

			}else{
				tmp = POW[x_num]*(POW[y_num]-1);
			}
			break;
		case 4:
			/*★複数文字にまたがるyの中で、少なくとも1つ1があれば良いと解釈★*/
			y_FLG = false;
			y_num = 0;
			for(int k = 5; k <= 7; k++){
				if(line[start_pos][k] == '1'){
					y_FLG = true;
				}else if(line[start_pos][k] == 'x'){
					y_num++;
				}
			}
			for(int k = 2; k <= 3; k++){
				if(line[start_pos+1][k] == '1'){
					y_FLG = true;
				}else if(line[start_pos+1][k] == 'x'){
					y_num++;
				}
			}

			x_num = 0;
			for(int k = 4; k <= 7; k++){
				if(line[start_pos+1][k] == 'x')x_num++;
			}
			for(int k = 2; k <= 7; k++){
				if(line[start_pos+2][k] == 'x')x_num++;
			}
			for(int k = 2; k <= 7; k++){
				if(line[start_pos+3][k] == 'x')x_num++;
			}
			if(y_FLG){

				tmp = POW[x_num]*POW[y_num];

			}else{
				tmp = POW[x_num]*(POW[y_num]-1);
			}
			break;
		}
		tmp %= NUM;
		ret += tmp*recursive(start_pos+i);
		ret %= NUM;
	}

	return dp[start_pos] = ret%NUM;
}

void func(){

	for(int i = 0; i < N; i++){
		scanf("%s",line[i]);
	}

	for(int i = 0; i < N; i++)dp[i] = -1;
	dp[N] = 1;

	printf("%lld\n",recursive(0));
}

int main(){

	for(int i = 0; i < 25; i++){
		POW[i] = pow(2,i);
		POW[i] %= NUM;
	}

	while(true){
		scanf("%d",&N);
		if(N == 0)break;

		func();
	}

	return 0;
}

