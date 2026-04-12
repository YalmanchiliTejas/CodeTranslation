#include<stack>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main(void){
	stack<char> st[100];
	char input[10],moving;
	int n,data,data2,cnt=0;	//n=山の数(n<=100)、data,data2=作業変数
	char pop_ans[100000];
	int i;	//i=ループカウンタ
	
	scanf("%d",&n);
	while(1){
		fgets(input,sizeof(input),stdin);

		if(input[0]=='q'){
			break;
		}
		else if(input[0]=='m'){
			data=atoi(&input[5]);
			data2=atoi(&input[7]);
			moving=st[data].top();
			st[data2].push(moving);
			st[data].pop();
		}
		else if(input[0]=='p'){
			if(input[1]=='u'){
				data=atoi(&input[5]);
				//atoi=文字列で表現された数値をint型の数値に変換
				st[data].push(input[7]);
			}
			else{
				data=atoi(&input[4]);
				pop_ans[cnt]=st[data].top();
				cnt++;
				st[data].pop();
			}
		}
	}
	for(i=0;i<cnt;i++){
		printf("%c\n",pop_ans[i]);
	}

	return 0;
}