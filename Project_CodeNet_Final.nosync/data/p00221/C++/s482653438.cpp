#include<iostream>
#include<string>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;

bool FizzBuzz(int i, string s){
	if(i%15 == 0) return s == "FizzBuzz";
	else if(i%3 == 0) return s == "Fizz";
	else if(i%5 == 0) return s == "Buzz";
	else return atoi(s.c_str()) == i;
}

int main(){
	int m, n;
	queue<int> p;
	string s;
	while(cin >> n >> m, n || m){
		for(int i=1; i <= n; i++) p.push(i);

		for(int i=1; i <= m; i++){
			cin >> s;
			if(p.size() == 1) continue;
			if(FizzBuzz(i, s)) p.push(p.front());
			p.pop();
		}
		if(!p.empty()){
			while(p.front() > p.back()){
				p.push(p.front());
				p.pop();
			}

			bool isFirst = true;
			while(!p.empty()){
				if(!isFirst) cout << " ";
				cout << p.front();
				p.pop();
				isFirst = false;
			}
			cout << endl;
		}
	}
}