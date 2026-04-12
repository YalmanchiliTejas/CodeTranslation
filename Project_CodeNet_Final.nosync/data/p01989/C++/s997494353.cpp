#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define NUM 15
int length;
int ans;
char buf[NUM];

bool is_ok(int num){

	return num >= 0 && num <= 255;
}

void recursive(int num,int index,int num_decided){

	if(!is_ok(num))return;

	if(num_decided == 4){

		if(index == length){
			ans++;
		}

		return;
	}

	//今回の場所で区切る
	int next_num = 10*num+(buf[index]-'0');

	if(is_ok(next_num)){
		recursive(0,index+1,num_decided+1);
	}

	if(buf[index] == '0')return; //leading zeroは不可

	//続ける
	recursive(next_num,index+1,num_decided);
}

int main(){

	scanf("%s",buf);

	for(length = 0; buf[length] != '\0'; length++);

	ans = 0;

	recursive(0,0,0);

	printf("%d\n",ans);

	return 0;
}

