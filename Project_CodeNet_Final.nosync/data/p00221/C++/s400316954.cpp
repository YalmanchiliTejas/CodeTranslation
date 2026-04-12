#include <iostream>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

int main(){
	queue<int> qu;
	int m,n,flag = 0;
	while(1){
		cin >> m >> n;
		if(!m && !n) break;
		for(int i = 1;i <= m;i++) qu.push(i);
		for(int i = 1;i <= n;i++){
			string s;
			cin >> s;
			if(qu.size() == 1) continue;
			if(i % 3 == 0){
				if(i % 5 == 0){
					if(s != "FizzBuzz") flag = 1;
				}else{
					if(s != "Fizz") flag = 1;
				}
			}
			else if(i % 5 == 0){
				if(s != "Buzz") flag = 1;
			}
			else{
				int n;
				stringstream ss;
				ss << s;
				ss >> n;
				if(n != i) flag = 1; 
			}
			int p = qu.front();
			qu.pop();
			if(!flag) qu.push(p);
			flag = 0;
		}
		priority_queue<int,vector<int>,greater<int> > pqu;
		for(;!qu.empty();) {
			pqu.push(qu.front());
			qu.pop();
		}
		if(!pqu.empty()) {
			cout << pqu.top();
			pqu.pop();
		}
		for(;!pqu.empty();){
			cout << " " << pqu.top();
			pqu.pop();
		}
		cout << endl;
	}
	return 0;
}