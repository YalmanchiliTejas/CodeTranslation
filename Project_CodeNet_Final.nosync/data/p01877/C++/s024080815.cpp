#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <time.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


ll *min_data,*max_data,*add_data;
ll first_table[500000];
int N = 1;

void init(ll first_N){
	while(N < first_N)N *= 2;
}

void add(int left,int right,ll value,int node_id,int node_left,int node_right){

	if(right < node_left || left > node_right){
		return;
	}
	else if(left <= node_left && right >= node_right){

		add_data[node_id] += value;

		while(node_id != 0){

			node_id = (node_id-1)/2;
			min_data[node_id] = min(min_data[2*node_id+1]+add_data[2*node_id+1],min_data[2*node_id+2]+add_data[2*node_id+2]);
			max_data[node_id] = max(max_data[2*node_id+1]+add_data[2*node_id+1],max_data[2*node_id+2]+add_data[2*node_id+2]);
		}
	}else{

		add(left,right,value,2*node_id+1,node_left,(node_left+node_right)/2);
		add(left,right,value,2*node_id+2,(node_left+node_right)/2+1,node_right);
	}
}

ll getMin(int left,int right,int node_id,int node_left,int node_right){
	if(right < node_left || left > node_right)return BIG_NUM;
	else if(left <= node_left && right >= node_right){
		return min_data[node_id]+add_data[node_id];

	}else{

		ll  left_min  = getMin(left,right,2*node_id+1,node_left,(node_left+node_right)/2);
		ll  right_min = getMin(left,right,2*node_id+2,(node_left+node_right)/2+1,node_right);
		return min(left_min,right_min)+add_data[node_id];
	}
}

ll getMax(int left,int right,int node_id,int node_left,int node_right){
	if(right < node_left || left > node_right)return -BIG_NUM;
	else if(left <= node_left && right >= node_right){
		return max_data[node_id]+add_data[node_id];

	}else{

		ll  left_max  = getMax(left,right,2*node_id+1,node_left,(node_left+node_right)/2);
		ll  right_max = getMax(left,right,2*node_id+2,(node_left+node_right)/2+1,node_right);
		return max(left_max,right_max)+add_data[node_id];
	}
}

int main(){

	int first_N;
	scanf("%d",&first_N);

	for(int i = 0; i < first_N; i++)scanf("%lld",&first_table[i]);

	for(int i = 0; i < first_N/2; i++){
		first_table[i] -= first_table[(first_N-1)-i];
	}

	first_N /= 2;
	init(first_N);

	min_data = new ll[2*N-1];
	max_data = new ll[2*N-1];
	add_data = new ll[2*N-1];

	for(ll i = 0; i <= 2*N-2; i++){
		min_data[i] = 0;
		max_data[i] = 0;
		add_data[i] = 0;
	}

	for(int i = 0; i < first_N; i++){
		add(i,i,first_table[i],0,0,N-1);
	}

	int Q;
	scanf("%d",&Q);

	int left,right,tmp,calc_left;
	ll add_value;

	for(int i = 0; i < Q; i++){
		scanf("%d %d %lld",&left,&right,&add_value);
		left--;
		right--;

		if(left >= first_N){

			tmp = right;
			right = (2*first_N-1)-left;
			left = (2*first_N-1)-tmp;

			add(left,right,-add_value,0,0,N-1);

		}else{ // left < first_N

			if(right < first_N){
				add(left,right,add_value,0,0,N-1);

			}else{ //right > first_N

				if(left+right == 2*first_N-1){
					//Do nothing
				}else{

					calc_left = (2*first_N-1)-right;

					if(calc_left < left){

						right = left-1;
						left = calc_left;
						add(left,right,-add_value,0,0,N-1);

					}else{

						right = calc_left-1;
						add(left,right,add_value,0,0,N-1);
					}
				}
			}
		}

		if(getMin(0,first_N-1,0,0,N-1) == 0 && getMax(0,first_N-1,0,0,N-1) == 0){
			printf("1\n");
		}else{
			printf("0\n");
		}
	}

	return 0;
}

