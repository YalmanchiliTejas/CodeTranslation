#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <vector>
using namespace std;

bool fizzbuzz(int n,string s){
	if(n%15==0)return (s != "FizzBuzz");
	if(n%3==0)return  (s != "Fizz");
	if(n%5==0)return  (s != "Buzz");
	
	for(int i=0;i<s.length();i++){
		if(s[i]<'0'||s[i]>'9')return true;
	}
	
	/*ツつ「ツづォツつ「ツづォツ妥篠催エ*/
	/*int zero = 0;
	for(int i=0;i<s.length();i++){
		if(s[i] == '0')zero++;
		else break;
	}
	s = s.substr(zero,s.length()-zero);
	if(s.length()>8)return true;
	*/
	return (atoi(s.c_str()) != n);
}

int main(){
	int n,m;
	string s;
	
	while(scanf("%d %d\n",&m,&n), m){
	
		vector<int> rem(m);
		for(int i=0;i<m;i++){
			rem[i] = i+1;
		}
		int c = 0;
		for(int i=1;i<=n;i++){
			getline(cin,s);
			if(rem.size() == 1)continue;
			if( fizzbuzz(i,s) ){
				rem.erase(remove(rem.begin(),rem.end(),rem[c]),rem.end());
				c %= rem.size();
			}else{
				c =(c+1)%rem.size();
			}
		}
		for(int i=0;i<rem.size();i++){
			cout << (i?" ":"") << rem[i];
		}
		cout << endl;
	}
}