using namespace std;
#include <iostream>
#include <string>
#include <set>
#include <functional>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
string cor(int num){
	if(num%3==0&&num%5==0)return "FizzBuzz";
	else if(num%3==0)return "Fizz";
	else if(num%5==0)return "Buzz";
	else{
		std::stringstream ss;
		ss << num;
		return ss.str();
	}
}
int main()
{
	int m,n;
	while(cin>>m>>n&&(m||n)){
		int alone=-1;
		bool ex[10001]={};
		for(int i=1;i<=m;i++)ex[i]=true;
		int last=0;
		int count=m;
		for(int i=1;i<=n;i++){
			if(count==1)alone=last;
			string num;cin>>num;
			int p=last!=m?last+1:1;
			while(!ex[p]){p==m?p=1:p++;}//sellect p
			if(num!=cor(i)){ex[p]=false;count--;}
			last=p;
		}
		if(alone==-1){
			int lex=1;
			for(int i=1;i<=m;i++)if(ex[i])lex=i;
			for(int i=1;i<=lex;i++)if(ex[i])printf(i==lex?"%d\n":"%d ",i);
		}else{
			printf("%d\n",alone);
		}
	}
    return 0;
}