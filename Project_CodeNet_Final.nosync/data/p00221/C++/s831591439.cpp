#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;

bool judge(const int x,const char str[]){
	
	char ans[1000];
	
	if(x%3 ==0 && x%5 == 0)
		strcpy(ans,"FizzBuzz");
	else if(x%3==0)
		strcpy(ans,"Fizz");
	else if(x%5==0)
		strcpy(ans,"Buzz");
	else
		sprintf(ans,"%d",x);
	
	/*
	cout << "judge" << endl;
	cout << "-" << str << "-" << endl;
	cout << "-" << ans << "-" << endl;
	*/
	if( strcmp(ans,str) )return false;
	
	return true;
}

int main(void){
	int m,n;
	while(scanf("%d%d", &m, &n) && m != 0 && n != 0){
		
		queue<int> Q;
		char str[1000];
		vector<int> ans;
		
		for(int i = 1; i <= m; i++)
			Q.push(i);
		
		for(int i = 1; i <= n; i++){
			scanf("%s", str);
			if(Q.size() == 1)continue;
			
			if( judge(i,str) ){
				Q.push(Q.front());
				Q.pop();
			}else{
				Q.pop();
			}
		}
		
		while(!Q.empty()){
			ans.push_back(Q.front());
			Q.pop();
		}
		
		sort(ans.begin(),ans.end());
		
		for(int i = 0; i < ans.size(); i++){
			printf("%d%s",ans[i],i==ans.size()-1?"\n":" ");
		}
	}
	return 0;
}