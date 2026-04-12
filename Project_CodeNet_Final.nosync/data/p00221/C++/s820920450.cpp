#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<cstdlib>

using namespace std;

bool mem[1001];

bool FizzBuzz(int a,string str){
	if(str=="FizzBuzz"){
		if(a%15==0)return true;
		else return false;
	}
	else if(str=="Fizz"){
		if(a%3==0)return true;
		else return false;
	}
	else if(str=="Buzz"){
		if(a%5==0)return true;
		else return false;
	}
	else{
		const char* ss=str.c_str();
		int s=atoi(ss);
		if(s==a && a%3!=0 && a%5!=0)return true;
		else return false;
	}
}

int main(void){
	while(1){
		int a,b,m,n;
		vector<string> str;
		cin >> m >> n;
		if(m==0 && n==0)break;
		for(a=0;a<=1000;a++){
			mem[a]=true;
		}
		for(a=1;a<=n;a++){
			string s;
			cin >> s;
			str.push_back(s);
		}
		int j=1,jj;
		for(a=1;a<=n;a++){
			if(!FizzBuzz(a,str[a-1]))mem[j]=false;
			bool ch=true,cc=false;
			jj=j;
			j++;
			if(j>m)j=1;
			while(ch){
				if(j>m)j=1;
				if(mem[j]==false){
					j++;
				}else ch=false,cc=true;
				if(jj==j)ch=false;
			}
			if(cc==false)break;
		}
		bool nyu=false;
		for(a=1;a<=m;a++){
			if(mem[a]==true){
				if(nyu==true)printf(" %d",a);
				else printf("%d",a);
				nyu=true;
			}
		}
		cout << endl;
	}
	return 0;
}