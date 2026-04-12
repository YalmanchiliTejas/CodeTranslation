#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

inline int toint(string str){
	istringstream iss(str);
	int ret;
	iss >> ret;
	return ret;
}

int main(void){
	int m,n;
	while(cin >> m >> n){
		if(!(m|n)) break;
		string str;
		bool isleft[m];
		bool ended = false;
		int turn = 0;
		memset(isleft,true,sizeof(isleft));
		
		for(int i=1;i<=n;i++){
			cin >> str;
			if(ended) continue;
			if(i%5==0&&i%3==0){
				//FizzBuzz
				if(str != "FizzBuzz") isleft[turn] = false;
			}else if(i%5==0){
				//Buzz
				if(str != "Buzz") isleft[turn] = false;
			}else if(i%3==0){
				//Fizz
				if(str != "Fizz") isleft[turn] = false;
			}else{
				bool bad = false;
				for(int j=0;j<str.size();j++){
					if(!( '0' <= str[j] && str[j] <= '9')) bad = true;
				}
				if(toint(str) != i || bad) isleft[turn] = false;
				//else
			}
			int begin=turn;
			do{
				turn++;
				turn %= m;
			}while(isleft[turn] == false);
			
			int cnt=0;
			for(int j=0;j<m;j++){
				if(isleft[j]) cnt++;
			}
			if(cnt==1) ended = true;
		}
		
		vector<int> v;
		for(int i=0;i<m;i++){
			if(isleft[i]){
				v.push_back(i+1);
			}
		}
		for(int i=0;i<v.size()-1;i++){
			cout << v[i] << " ";
		}
		cout << v.back() << endl;
	}
}