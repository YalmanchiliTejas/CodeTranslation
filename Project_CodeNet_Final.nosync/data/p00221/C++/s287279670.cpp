#include <iostream>
#include <queue>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
	int s, t, v, a[1000];
	string str;
	
	while(1){
		cin >> s >> t;
		if(s == 0 && t == 0){
			break;
		}
		queue<int> que;
		
		for(int i = 1; i <= s; i++){
			que.push(i);
		}
		
		for(int i = 1; i <= t; i++){
			cin >> str;
			if(que.size() == 1){
				continue;
			}
			if(i%3 == 0 && i%5 == 0){
				if(str == "FizzBuzz"){
					que.push(que.front());
				}
			} else if(i%3 == 0){
				if(str == "Fizz"){
					que.push(que.front());
				}
			} else if(i%5 == 0){
				if(str == "Buzz"){
					que.push(que.front());
				}
			} else {
				v = atoi(str.c_str());
				if(v == i){
					que.push(que.front());
				}
			}
			que.pop();
		}
		v = 0;
		while(!que.empty()){
			a[v++] = que.front();
			que.pop();
		}
		sort(a, a+v);
		
		cout << a[0];
		for(int i = 1; i < v; i++){
			cout << " " << a[i];
		}
		cout << endl;
	}
	
	return 0;
}