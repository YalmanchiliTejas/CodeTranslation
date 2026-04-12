#include<stdio.h>
#include<stack>
using namespace std;
char str[6];
stack<char> S[100];

int main(){
	int a;
	scanf("%d",&a);
	while(1){
		scanf("%s",str);
		if(str[0]=='q')return 0;
		if(str[0]=='m'){
			int b,c;
			scanf("%d%d",&b,&c);
			b--;c--;
			S[c].push(S[b].top());
			S[b].pop();
		}else if(str[0]=='p'&&str[1]=='u'){
			int b;scanf("%d%s",&b,str);
			b--;S[b].push(str[0]);
		}else{
			int b;scanf("%d",&b);b--;printf("%c\n",S[b].top());S[b].pop();
		}
	}
}