#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
//#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;

#define BIG_NUM 1000
#define NUM 531441

enum Type{
	FROG,
	Kappa,
	Weasel,
};

enum ACT{
	USE_1,
	USE_2,
	NONE,
};

struct Info{

	short result[3];
};

int POW[12];
int noble[12],action[3][2];
int work[12],value[3];
Type type_array[3] = {FROG,Kappa,Weasel};
ACT act_array[3] = {USE_1,USE_2,NONE},history[12];
Info dp[2][12][NUM];

Info recursive(int turn,int state,bool kappa_mind){

	if(turn == 12){

		Info ret;

		for(int i = 0; i < 3; i++){

			ret.result[i] = value[i];
		}

		return ret;
	}

	if(dp[kappa_mind][turn][state].result[0] != -(BIG_NUM+1)){

		return dp[kappa_mind][turn][state];
	}

	bool did_use[2] = {false,false};
	Type type = type_array[(turn)%3];

	int pre_work[12];

	for(int k = 0; k < 12; k++){

		pre_work[k] = work[k];
	}

	for(int i = (turn%3); i < turn; i += 3){

		if(history[i] == USE_1){

			did_use[USE_1] = true;

		}else if(history[i] == USE_2){

			did_use[USE_2] = true;
		}
	}

	Info tmp[3];

	if(kappa_mind == false || type == Kappa){

		if(kappa_mind == false){

			tmp[USE_1].result[type] = -BIG_NUM;
			tmp[USE_2].result[type] = -BIG_NUM;

		}else{

			tmp[USE_1].result[FROG] = BIG_NUM;
			tmp[USE_2].result[FROG] = BIG_NUM;
		}

		int rest_num = 12-turn;

		if(!did_use[USE_1]){

			int pre_value = value[type];

			if(rest_num >= action[type][USE_1]){

				value[type] += work[action[type][USE_1]-1];

				for(int k = action[type][USE_1]; k < 12; k++){

					work[k-1] = work[k];
				}
			}else{

				value[type] += work[0];

				for(int k = 1; k < 12; k++){

					work[k-1] = work[k];
				}
			}

			history[turn] = USE_1;
			tmp[USE_1] = recursive(turn+1,state,kappa_mind);

			for(int i = 0; i < 12; i++){

				work[i] = pre_work[i];
			}

			value[type] = pre_value;
		}

		if(!did_use[USE_2]){

			int pre_value = value[type];

			if(rest_num >= action[type][USE_2]){

				value[type] += work[action[type][USE_2]-1];

				for(int k = action[type][USE_2]; k < 12; k++){

					work[k-1] = work[k];
				}
			}else{

				value[type] += work[0];

				for(int k = 1; k < 12; k++){

					work[k-1] = work[k];
				}
			}

			history[turn] = USE_2;
			tmp[USE_2] = recursive(turn+1,state+POW[turn],kappa_mind);

			for(int i = 0; i < 12; i++){

				work[i] = pre_work[i];
			}

			value[type] = pre_value;
		}

		int pre_value = value[type];

		value[type] += work[0];

		for(int k = 1; k < 12; k++){

			work[k-1] = work[k];
		}

		history[turn] = NONE;

		tmp[NONE] = recursive(turn+1,state+2*POW[turn],kappa_mind);

		for(int i = 0; i < 12; i++){

			work[i] = pre_work[i];
		}

		value[type] = pre_value;

		if(kappa_mind == false){

			int max_value = -BIG_NUM,num_max = 0;
			ACT max_act;

			for(int i = 0; i < 3; i++){

				if(max_value < tmp[act_array[i]].result[type]){

					max_value = tmp[act_array[i]].result[type];
					max_act = act_array[i];
					num_max = 1;
				}else if(max_value == tmp[act_array[i]].result[type]){

					num_max++;
				}
			}

			if(num_max == 1){

				return dp[kappa_mind][turn][state] = tmp[max_act];

			}else if(num_max == 3){

				return dp[kappa_mind][turn][state] = tmp[NONE];

			}else{ //num_max == 2

				if(tmp[USE_1].result[type] < max_value){

					return dp[kappa_mind][turn][state] = tmp[NONE];

				}else if(tmp[USE_2].result[type] < max_value){

					return dp[kappa_mind][turn][state] = tmp[NONE];

				}else{ //tmp[NONE].result[type] < max_value

					if(action[type][USE_1] < action[type][USE_2]){

						return dp[kappa_mind][turn][state] = tmp[USE_1];

					}else{

						return dp[kappa_mind][turn][state] = tmp[USE_2];
					}
				}
			}

		}else{

			int min_value = BIG_NUM,num_min = 0;
			ACT min_act;

			for(int i = 0; i < 3; i++){

				if(min_value > tmp[act_array[i]].result[FROG]){

					min_value = tmp[act_array[i]].result[FROG];
					min_act = act_array[i];
					num_min = 1;
				}else if(min_value == tmp[act_array[i]].result[FROG]){

					num_min++;
				}
			}

			if(num_min == 1){

				return dp[kappa_mind][turn][state] = tmp[min_act];

			}else if(num_min == 3){

				return dp[kappa_mind][turn][state] = tmp[NONE];

			}else{ //num_min == 2

				if(tmp[USE_1].result[FROG] > min_value){

					return dp[kappa_mind][turn][state] = tmp[NONE];

				}else if(tmp[USE_2].result[FROG] > min_value){

					return dp[kappa_mind][turn][state] = tmp[NONE];

				}else{ //tmp[NONE].result[FROG] > min_value

					if(action[type][USE_1] < action[type][USE_2]){

						return dp[kappa_mind][turn][state] = tmp[USE_1];

					}else{

						return dp[kappa_mind][turn][state] = tmp[USE_2];
					}
				}
			}
		}

	}else{

		tmp[USE_1].result[type] = -BIG_NUM;
		tmp[USE_2].result[type] = -BIG_NUM;

		int rest_num = 12-turn;

		if(!did_use[USE_1]){

			int pre_value = value[type];

			if(rest_num >= action[type][USE_1]){

				value[type] += work[action[type][USE_1]-1];

				for(int k = action[type][USE_1]; k < 12; k++){

					work[k-1] = work[k];
				}
			}else{

				value[type] += work[0];

				for(int k = 1; k < 12; k++){

					work[k-1] = work[k];
				}
			}

			history[turn] = USE_1;
			tmp[USE_1] = recursive(turn+1,state,false);

			for(int i = 0; i < 12; i++){

				work[i] = pre_work[i];
			}

			value[type] = pre_value;
		}

		if(!did_use[USE_2]){

			int pre_value = value[type];

			if(rest_num >= action[type][USE_2]){

				value[type] += work[action[type][USE_2]-1];

				for(int k = action[type][USE_2]; k < 12; k++){

					work[k-1] = work[k];
				}
			}else{

				value[type] += work[0];

				for(int k = 1; k < 12; k++){

					work[k-1] = work[k];
				}
			}

			history[turn] = USE_2;
			tmp[USE_2] = recursive(turn+1,state+POW[turn],false);

			for(int i = 0; i < 12; i++){

				work[i] = pre_work[i];
			}

			value[type] = pre_value;
		}

		int pre_value = value[type];

		value[type] += work[0];

		for(int k = 1; k < 12; k++){

			work[k-1] = work[k];
		}

		history[turn] = NONE;

		tmp[NONE] = recursive(turn+1,state+2*POW[turn],false);

		for(int i = 0; i < 12; i++){

			work[i] = pre_work[i];
		}

		value[type] = pre_value;

		int max_value = -BIG_NUM,num_max = 0;
		ACT max_act;

		for(int i = 0; i < 3; i++){

			if(max_value < tmp[act_array[i]].result[type]){

				max_value = tmp[act_array[i]].result[type];
				max_act = act_array[i];
				num_max = 1;
			}else if(max_value == tmp[act_array[i]].result[type]){

				num_max++;
			}
		}

		Info ret2;

		if((num_max == 1 && max_act == NONE) || (num_max == 3) || (num_max == 2 && tmp[USE_1].result[type] < max_value) ||
				(num_max == 2 && tmp[USE_2].result[type] < max_value)){ //NONE

			pre_value = value[type];

			value[type] += work[0];

			for(int k = 1; k < 12; k++){

				work[k-1] = work[k];
			}

			history[turn] = NONE;

			ret2 = recursive(turn+1,state+2*POW[turn],true);

			for(int i = 0; i < 12; i++){

				work[i] = pre_work[i];
			}

			value[type] = pre_value;

		}else if((num_max == 1 && max_act == USE_1) ||
				(tmp[NONE].result[type] < max_value && num_max == 2 && action[type][USE_1] < action[type][USE_2])){ //USE_1

			int pre_value = value[type];

			if(rest_num >= action[type][USE_1]){

				value[type] += work[action[type][USE_1]-1];

				for(int k = action[type][USE_1]; k < 12; k++){

					work[k-1] = work[k];
				}
			}else{

				value[type] += work[0];

				for(int k = 1; k < 12; k++){

					work[k-1] = work[k];
				}
			}

			history[turn] = USE_1;
			ret2 = recursive(turn+1,state,true);

			for(int i = 0; i < 12; i++){

				work[i] = pre_work[i];
			}

			value[type] = pre_value;

		}else{ //USE_2

			int pre_value = value[type];

			if(rest_num >= action[type][USE_2]){

				value[type] += work[action[type][USE_2]-1];

				for(int k = action[type][USE_2]; k < 12; k++){

					work[k-1] = work[k];
				}
			}else{

				value[type] += work[0];

				for(int k = 1; k < 12; k++){

					work[k-1] = work[k];
				}
			}

			history[turn] = USE_2;
			ret2 = recursive(turn+1,state+POW[turn],true);

			for(int i = 0; i < 12; i++){

				work[i] = pre_work[i];
			}

			value[type] = pre_value;
		}

		return dp[kappa_mind][turn][state] = ret2;
	}
}

int main(){

	POW[0] = 1;

	for(int i = 1; i < 12; i++){

		POW[i] = POW[i-1]*3;
	}

	for(int i = 0; i < 12; i++){

		scanf("%d",&noble[i]);
	}

	for(int i = 0; i < 3; i++){

		scanf("%d %d",&action[type_array[i]][0],&action[type_array[i]][1]);
	}

	for(int i = 0; i < 12; i++){

		work[i] = noble[11-i];
	}

	for(int i = 0; i < 3; i++){

		value[i] = 0;
	}

	for(int i = 0; i < 2; i++){
		for(int k = 0; k < 12; k++){
			for(int state = 0; state < NUM; state++){
				for(int a = 0; a < 3; a++){
					dp[i][k][state].result[a] = -(BIG_NUM+1);
				}
			}
		}
	}

	recursive(0,0,false);
	Info ret = recursive(0,0,true);

	printf("%d %d %d\n",ret.result[FROG],ret.result[Kappa],ret.result[Weasel]);

	return 0;
}


