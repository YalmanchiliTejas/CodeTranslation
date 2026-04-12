#include<cstdio>
#include<string>
#include<iostream>

using namespace std;


int main(void){
	string lef="qwertasdfgzxcvb";
	while(1){
		string str;
		cin >> str;
		if(str=="#")break;
		int cnt=0,flag=-1;
		for(int i=0;i<str.size();i++){
			bool lr=false;
			for(int j=0;j<lef.size();j++){
				if(str[i]==lef[j])lr=true;
			}
			if(flag==0 && !lr){
				flag=1;
				cnt++;
			}
			if(flag==1 && lr){
				flag=0;
				cnt++;
			}
			if(flag==-1){
				if(lr)flag=0;
				else flag=1;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}