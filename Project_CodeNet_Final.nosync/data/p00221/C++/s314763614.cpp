#include<iostream>
#include <list>
#include <cstdlib>
#include <algorithm>
using namespace std;

int m,n;

int main(void){
	 while(cin >> m >> n,m|n){
		list <int> sur;
		for(int i=1;i<=m;i++)
			sur.push_back(i);
		typeof(sur.begin()) itr;
		itr=sur.begin();
		for(int i=1;i<=n;i++){
			string S;
			bool ok=false;
			cin >> S;
			if(itr==sur.end())
				itr=sur.begin();
			if(sur.size()==1)
				continue;
			if(!(i%15)&& (S =="FizzBuzz"))
				ok=true;
			else if(!(i%5)&& (S =="Buzz"))
				ok=true;
			else if(!(i%3)&& (S =="Fizz"))
				ok=true;
			else if(i==atoi(S.c_str())&&(i%3&&i%5))
				ok=true;
			if(ok){
				itr++;
			}else{
				itr=sur.erase(itr);
			}
		}
		cout << *(sur.begin() );
		if(sur.size()!=1)
			for(typeof(sur.begin()) it=++sur.begin(); it!=sur.end();it++)
				cout << " " << *it;
		cout << endl;
	}
}