#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define NUM 10001
#define SIZE 501

enum Type{
	A,
	B,
};

enum Which{
	HEAD_MATCH,
	NOT,
};

struct Node{
	int parent_id,children[10],suffix_link;
	bool finish_FLG;
};

struct Info{
    Info(int arg_node_id,int arg_ch){
        node_id = arg_node_id;
        ch = arg_ch;
    }

    int node_id,ch;
};

struct State{
	State(int arg_pos,int arg_num){
		pos = arg_pos;
		num = arg_num;
	}
	int pos,num;
};

int next_loc[SIZE][10];
int len[2],len_C;
int root;
int memo[NUM][SIZE][2];
int dp[NUM][SIZE];
ll left_table[NUM][2],right_table[NUM][2];
ll POW[NUM],num_future[NUM][2];bool is_pre_ok[SIZE],match_check[NUM],is_bad_trie_pos[NUM];
char buf[2][NUM],C[SIZE];
Node nodes[SIZE];


int recursive(Type type,bool c_zero,int digit,int start_digit,int trie_pos,bool leading_zero,bool head_match){

	ll ret = 0;
	int limit,next_trie_pos;

	if(digit < start_digit){

		if(head_match){
			limit = buf[type][digit]-'0';
		}else{
			limit = 9;
		}

		if(digit == start_digit-1){

			for(int next = 0; next <= limit; next++){
				if((c_zero == true && leading_zero == false && next == 0) ||
						(c_zero == false && next_loc[trie_pos][next] == len_C))continue;

				if(leading_zero == true && next == 0){
					next_trie_pos = root;
				}else{
					next_trie_pos = next_loc[trie_pos][next];
					if(!is_pre_ok[next_trie_pos])continue;
				}

				ret += recursive(type,c_zero,digit+1,start_digit,next_trie_pos,
										leading_zero && next == 0,head_match && next == limit);

				ret %= MOD;
			}

		}else{

			for(int next = 0; next <= limit; next++){
				if((c_zero == true && leading_zero == false && next == 0) ||
						(c_zero == false && next_loc[trie_pos][next] == len_C))continue;

				if(leading_zero == true && next == 0){
					next_trie_pos = root;
				}else{
					next_trie_pos = next_loc[trie_pos][next];
				}

				ret += recursive(type,c_zero,digit+1,start_digit,next_trie_pos,
														leading_zero && next == 0,head_match && next == limit);
				ret %= MOD;
			}
		}
		return (int)ret;

	}else if(digit >= start_digit && digit <= start_digit+len_C-1){

		if(c_zero == true && leading_zero == true){

			if(digit == len[type]-1){
				return 1;
			}else{
				return 0;
			}
		}

		if(head_match){

			if(C[digit-start_digit]-'0' > buf[type][digit]-'0'){
				return 0;

			}else{

				ll ret = recursive(type,c_zero,digit+1,start_digit,next_loc[trie_pos][C[digit-start_digit]-'0'],
						false,head_match && C[digit-start_digit] == buf[type][digit]);

				return (int)(ret%MOD);
			}

		}else{

			ll ret = recursive(type,c_zero,digit+1,start_digit,next_loc[trie_pos][C[digit-start_digit]-'0'],
					false,false);

			return (int)(ret%MOD);
		}

	}else{

		if(digit == len[type])return memo[digit][trie_pos][head_match] = 1;

		if(memo[digit][trie_pos][head_match] != -1)return memo[digit][trie_pos][head_match];

		if(head_match){

			limit = buf[type][digit]-'0';

		}else{
			limit = 9;
		}

		for(int next = 0; next <= limit; next++){

			if(next_loc[trie_pos][next] == len_C){

				if(digit == len[type]-1){

					ret++;

				}else{

					if(head_match == true && next  == buf[type][digit]-'0'){
						ret += num_future[digit+1][HEAD_MATCH];
						ret %= MOD;
					}else{
						ret += num_future[len[type]-(digit+1)][NOT];
						ret %= MOD;
					}
				}
			}
			ret += recursive(type,c_zero,digit+1,start_digit,next_loc[trie_pos][next],
					false,head_match && next == limit);

			ret %= MOD;
		}

		return memo[digit][trie_pos][head_match] = (int)ret;
	}
}

void init(){

	for(int i = 0; i < NUM; i++){

		for(int a = 0; a < 2; a++){
			left_table[i][a] = 0;
			right_table[i][a] = 0;
		}

		for(int k = 0; k < SIZE; k++){

			memo[i][k][true] = -1;
			memo[i][k][false] = -1;

			dp[i][k] = 0;
		}
	}
}

int get_next_loc(int current_loc,int next){

	if(nodes[current_loc].children[next] != -1){

		return nodes[current_loc].children[next];

	}else{

		if(current_loc == root){
			return root;
		}

		for(current_loc = nodes[current_loc].suffix_link; current_loc != root; current_loc = nodes[current_loc].suffix_link){
			if(nodes[current_loc].children[next] != -1){
				break;
			}
		}
		if(nodes[current_loc].children[next] != -1){

			return nodes[current_loc].children[next];

		}else{

			return root;
		}
	}
}

void makeTrie(){

	int index = 1;

	nodes[root].suffix_link = -1;

	for(int i = 0; i <= len_C; i++){
		nodes[i].parent_id = -1;
		nodes[i].finish_FLG = false;
		for(int k = 0; k < 10; k++){
			nodes[i].children[k] = -1;
		}
	}

	int tmp_ch,tmp_loc,parent_id,tmp_index;

	tmp_index = 0;
	tmp_ch = C[tmp_index]-'0';

	tmp_loc = root;
	tmp_index = 0;

	while(true){

		parent_id = tmp_loc;

		nodes[tmp_loc].children[tmp_ch] = index++;

		tmp_loc = nodes[tmp_loc].children[tmp_ch];
		nodes[tmp_loc].parent_id = parent_id;

		tmp_index++;

		if(C[tmp_index] == '\0'){
			nodes[tmp_loc].finish_FLG = true;
			break;
		}
		tmp_ch = C[tmp_index]-'0';
	}
}

void makeSuffixLink(){

	int node_id;
	queue<Info> MAKE_SL;

	for(int i = 0; i < 10; i++){
		if(nodes[root].children[i] != -1){
			node_id = nodes[root].children[i];
			nodes[node_id].suffix_link = root;
			for(int k = 0; k < 10; k++){
				if(nodes[node_id].children[k] != -1){
					MAKE_SL.push(Info(nodes[node_id].children[k],k));
				}
			}
		}
	}

	int tmp_loc,tmp_ch;

	while(!MAKE_SL.empty()){
		node_id = MAKE_SL.front().node_id;
		tmp_ch = MAKE_SL.front().ch;
		MAKE_SL.pop();

		for(int i = 0; i < 10; i++){
			if(nodes[node_id].children[i] != -1){
				MAKE_SL.push(Info(nodes[node_id].children[i],i));
			}
		}

		for(tmp_loc = nodes[nodes[node_id].parent_id].suffix_link; tmp_loc != root; tmp_loc = nodes[tmp_loc].suffix_link){
			if(nodes[tmp_loc].children[tmp_ch] != -1){
				break;
			}
		}

		if(tmp_loc == root){
			if(nodes[root].children[tmp_ch] != -1){
				nodes[node_id].suffix_link = nodes[root].children[tmp_ch];
			}else{
				nodes[node_id].suffix_link = root;
			}
		}else{
			nodes[node_id].suffix_link = nodes[tmp_loc].children[tmp_ch];
		}
	}
}

void calc_future(Type type){

	ll num = buf[type][len[type]-1]-'0';
	num_future[len[type]-1][HEAD_MATCH] = num+1;

	for(int digit = len[type]-2; digit >= 0; digit--){
		num += POW[(len[type]-1)-digit]*(buf[type][digit]-'0');
		num %= MOD;
		num_future[digit][HEAD_MATCH] = num;
	}
}

int final_calc(Type type,bool c_zero){

	ll ret = 0;
	bool IS_SAME;

	int head_match_loc = root;
	bool head_match_FLG = true;

	for(int start_digit = 0; start_digit+len_C <=len[type]; start_digit++){

		if(start_digit == 0){
			recursive(type,c_zero,start_digit,start_digit,0,true,true);

			head_match_loc = next_loc[head_match_loc][buf[type][0]-'0'];

			if(head_match_loc == len_C){
				head_match_FLG = false;
			}

		}else{

			if(head_match_FLG){

				IS_SAME = false;

				if(is_pre_ok[head_match_loc]){

					IS_SAME = true;
					for(int i = 0; i < len_C; i++){
						if(buf[type][start_digit+i] != C[i]){
							IS_SAME = false;
							break;
						}
					}
				}
				if(IS_SAME){
					recursive(type,c_zero,start_digit+len_C,start_digit,len_C,false,true);
				}

				head_match_loc = next_loc[head_match_loc][buf[type][start_digit]-'0'];

				if(head_match_loc == len_C){
					head_match_FLG = false;
				}
			}
			recursive(type,c_zero,start_digit+len_C,start_digit,len_C,false,false);
		}
	}
	for(int digit = len_C; digit <= len[type]; digit++){
		right_table[digit][HEAD_MATCH] = max(0,memo[digit][len_C][true]);
		right_table[digit][NOT] = max(0,memo[digit][len_C][false]);
	}

	int limit,next_trie_pos;
	head_match_loc = root;
	head_match_FLG = true;

	for(int i = 0; i <= len[type]; i++){
		is_bad_trie_pos[i] = false;
	}

	vector<State> pre_uncount_pos,next_uncount_pos;

	for(int last_digit = 0; last_digit < len[type]-len_C; last_digit++){

		if(last_digit > 0){
			match_check[last_digit-1] = head_match_FLG;
		}

		if(last_digit == 0){

			for(int next = 1; next < buf[type][0]-'0'; next++){

				next_trie_pos = next_loc[root][next];
				if(next_trie_pos == len_C)continue;

				dp[last_digit][next_trie_pos]++;
			}

			head_match_loc = next_loc[head_match_loc][buf[type][last_digit]-'0'];

			if(head_match_loc == len_C){
				head_match_FLG = false;
			}

			if(!is_pre_ok[head_match_loc]){
				is_bad_trie_pos[last_digit] = true;

				if(head_match_loc != len_C){
					pre_uncount_pos.push_back(State(last_digit,1));
				}
			}

			continue;
		}

		if(head_match_FLG){

			limit = (buf[type][last_digit]-'0')-1;
			for(int next = 0; next <= limit; next++){

				if(c_zero == true && next == 0)continue;

				next_trie_pos = next_loc[head_match_loc][next];

				if(next_trie_pos != len_C && is_pre_ok[next_trie_pos] == false){
					next_uncount_pos.push_back(State(next_trie_pos,1));
				}

				if(next_trie_pos == len_C || is_pre_ok[next_trie_pos] == false)continue;

				dp[last_digit][next_trie_pos] += 1;
				dp[last_digit][next_trie_pos] %= MOD;
			}

			head_match_loc = next_loc[head_match_loc][buf[type][last_digit]-'0'];

			if(head_match_loc == len_C){
				head_match_FLG = false;
			}

			if(!is_pre_ok[head_match_loc]){
				is_bad_trie_pos[last_digit] = true;
			}
		}

		limit = 9;
		for(int pre_loc = 0; pre_loc <= len_C-1; pre_loc++){
			for(int next = 0; next <= limit; next++){

				if(dp[last_digit-1][pre_loc] == 0)continue;
				if(c_zero == true && next == 0)continue;

				next_trie_pos = next_loc[pre_loc][next];

				if(next_trie_pos != len_C && is_pre_ok[next_trie_pos] == false){
					next_uncount_pos.push_back(State(next_trie_pos,dp[last_digit-1][pre_loc]));
				}

				if(next_trie_pos == len_C || is_pre_ok[next_trie_pos] == false)continue;

				dp[last_digit][next_trie_pos] += dp[last_digit-1][pre_loc];
				dp[last_digit][next_trie_pos] %= MOD;
			}
		}

		limit = 9;

		for(int next = 1; next <= limit; next++){

			next_trie_pos = next_loc[root][next];

			if(next_trie_pos != len_C && is_pre_ok[next_trie_pos] == false){
				next_uncount_pos.push_back(State(next_trie_pos,1));
			}

			if(next_trie_pos == len_C || is_pre_ok[next_trie_pos] == false)continue;

			dp[last_digit][next_trie_pos] += 1;
			dp[last_digit][next_trie_pos] %= MOD;
		}

		for(int i = 0; i < pre_uncount_pos.size(); i++){
			for(int next = 0; next <= 9; next++){

				if(c_zero && next == 0)continue;

				next_trie_pos = next_loc[pre_uncount_pos[i].pos][next];

				if(next_trie_pos != len_C && is_pre_ok[next_trie_pos] == false){
					next_uncount_pos.push_back(State(next_trie_pos,pre_uncount_pos[i].num));
					continue;
				}
				dp[last_digit][next_trie_pos] += pre_uncount_pos[i].num;
				dp[last_digit][next_trie_pos] %= MOD;
			}
		}

		pre_uncount_pos.clear();
		for(int k = 0; k < next_uncount_pos.size(); k++){
			pre_uncount_pos.push_back(next_uncount_pos[k]);
		}
		next_uncount_pos.clear();
	}
	match_check[len[type]-len_C-1] = head_match_FLG;

	for(int last_digit = 0; last_digit < len[type]-len_C; last_digit++){

		if(match_check[last_digit]){

			left_table[last_digit][HEAD_MATCH] = 1;

		}else{
			left_table[last_digit][HEAD_MATCH] = 0;
		}

		if(!c_zero){
			left_table[last_digit][NOT] += 1;
		}

		if(match_check[last_digit] == true && is_bad_trie_pos[last_digit] == false){

			bool is_over = false;

			IS_SAME = true;
			for(int i = 0; i < len_C; i++){
				if(C[i] < buf[type][last_digit+1+i]){
					IS_SAME = false;
					break;
				}else if(C[i] > buf[type][last_digit+1+i]){
					IS_SAME = false;
					is_over = true;
					break;
				}
			}

			if(is_over == false && IS_SAME == false){
				left_table[last_digit][NOT] += 1;
			}
		}

		for(int pos = 0; pos <= len_C-1; pos++){
			left_table[last_digit][NOT] += dp[last_digit][pos];
			left_table[last_digit][NOT] %= MOD;
		}
	}

	for(int last_digit = -1; last_digit < len[type]-len_C; last_digit++){

		if(last_digit == -1){
			ret += right_table[len_C][HEAD_MATCH];
			ret += right_table[len_C][NOT];
			ret %= MOD;
			continue;
		}

		if(match_check[last_digit] == true && is_bad_trie_pos[last_digit] == false){
			IS_SAME = true;
			for(int i = 0; i < len_C; i++){
				if(buf[type][last_digit+1+i] != C[i]){
					IS_SAME = false;
					break;
				}
			}
			if(IS_SAME){
				ret += right_table[last_digit+len_C+1][HEAD_MATCH];
				ret %= MOD;
			}
		}

		ret += left_table[last_digit][NOT]*right_table[last_digit+len_C+1][NOT];
		ret %= MOD;
	}
	if(c_zero)ret++;

	return ret%MOD;
}

int main(){

	scanf("%s %s %s",buf[A],buf[B],C);

	int length;

	for(length = 0; buf[A][length] != '\0'; length++);
	len[A] = length;
	for(length = 0; buf[B][length] != '\0'; length++);
	len[B] = length;
	for(length = 0; C[length] != '\0'; length++);
	len_C = length;

	bool c_zero = (len_C == 1) && (C[0] == '0');

	root = 0;
	makeTrie();
	makeSuffixLink();

	for(int current_loc = 0; current_loc <= len_C; current_loc++){
		for(int next = 0; next <= 9; next++){

			next_loc[current_loc][next] = get_next_loc(current_loc,next);
		}
	}

	bool FLG;
	int tmp_loc;

	for(int start_loc = 0; start_loc <= len_C-1; start_loc++){

		FLG = true;
		tmp_loc = start_loc;

		for(int i = 0; i < len_C; i++){

			tmp_loc = next_loc[tmp_loc][C[i]-'0'];

			if(tmp_loc == len_C && i <= len_C-2){
				FLG = false;
				break;
			}
		}
		is_pre_ok[start_loc] = FLG;
	}

	ll minus_A = 0;

	for(int start_digit = 0; start_digit+len_C <= len[A]; start_digit++){

		FLG = true;

		for(int i = 0; i < len_C; i++){

			if(buf[A][start_digit+i] != C[i]){

				FLG = false;
				break;
			}
		}
		if(FLG)minus_A++;
	}

	ll num_A,num_B;

	POW[0] = 1;
	num_future[0][NOT] = 1;

	for(int i = 1; i < NUM; i++){

		POW[i] = POW[i-1]*10;
		POW[i] %= MOD;

		num_future[i][NOT] = POW[i];
	}

	init();
	calc_future(A);
	num_A = final_calc(A,c_zero);

	init();
	calc_future(B);
	num_B = final_calc(B,c_zero);

	ll ans = num_B-(num_A-minus_A);
	ans %= MOD;
	if(ans < 0)ans += MOD;

	printf("%lld\n",ans);

	return 0;
}

