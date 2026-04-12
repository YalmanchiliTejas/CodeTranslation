#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<set>
#include<list>
#include<queue>
#include<cmath>
#include<functional>
#include<algorithm>
#define INF (1<<29)
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;


long long lefttoright(const string &s){
	long long a=0,b=0;
	int i;
	char op;
	for(i=0;i<s.size()&&s[i]!='+'&&s[i]!='*';i++){
		a*=10;
		a+=s[i]-'0';
	}
	if(i==s.size())return a;
	op=s[i++];
	for(;i<s.size();i++){
		if(s[i]=='+'||s[i]=='*'){
			if(op=='+'){
				a+=b;
			}else{
				a*=b;
			}
			op=s[i];
			b=0;
		}else{
			b*=10;
			b+=s[i]-'0';
		}
	}
	if(op=='+'){
		a+=b;
	}else{
		a*=b;
	}
	return a;
}


long long mulfirst(const string &s){
	long long a=0;
	int i,j=-1;
	for(i=0;i<s.size();i++){
		if(s[i]=='+'){
			a+=lefttoright(s.substr(j+1,i-j-1));
			j=i;
		}
	}
	a+=lefttoright(s.substr(j+1,s.size()-j-1));
	return a;
}



int main(){
	string expr;
	int v;
	cin>>expr>>v;
	char ans[]="IMLU";
	cout<<ans[(v==mulfirst(expr))+2*(v==lefttoright(expr))]<<endl;
	return 0;
}