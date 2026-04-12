#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
typedef long long int ll;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000001
using namespace std;

enum Token{
	NONE,
	MULT,
	PLUS,
};

int length;

int left_to_right(char buf[18]){
	int ans = buf[0] - '0';

	Token token = NONE;

	for(int i = 1; i < length; i++){
		switch(buf[i]){
		case '+':
			token = PLUS;
			break;
		case '*':
			token = MULT;
			break;
		default: //??°???
			if(token == MULT){
				ans *= buf[i] - '0';
			}else if(token == PLUS){
				ans += buf[i] - '0';
			}
			break;
		}
	}

	return ans;
}

int multi_first(char buf[18]){

	int tmp;

	stack<int> NUM;
	stack<char> OP;

	NUM.push(buf[0]-'0');

	for(int i = 1; i < length; i++){
		if(buf[i] >= '0' && buf[i] <= '9'){

			if(OP.top() == '*'){
				OP.pop();
				tmp = NUM.top();
				NUM.pop();
				NUM.push(tmp*(buf[i]-'0'));
			}else{
				NUM.push(buf[i]-'0');
			}
		}else{
			OP.push(buf[i]);
		}
	}

	int ans = 0;
	while(!NUM.empty()){
		ans += NUM.top();
		NUM.pop();
	}
	return ans;
}

int main(){

	char buf[18];
	int num,rule_1,rule_2;

	scanf("%s",buf);
	scanf("%d",&num);

	for(length = 0;buf[length] != '\0'; length++);

	rule_1 = multi_first(buf);
	rule_2 = left_to_right(buf);

	if(num == rule_1 && num == rule_2){
		printf("U\n");
	}else if(num != rule_1 && num == rule_2){
		printf("L\n");
	}else if(num == rule_1 && num != rule_2){
		printf("M\n");
	}else{ //num != rule_1 && num != rule_2
		printf("I\n");
	}

	return 0;
}