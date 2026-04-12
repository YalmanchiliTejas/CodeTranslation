#include <iostream>
#include <stack>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

int main(){
	while(true){
		int n;
		cin >> n;
		if(n == 0){ break; }
		stack<pii> stk;
		for(int i = 0; i < n; i++){
			int color;
			cin >> color;
			if(stk.empty()){
				stk.push(pii(color, 1));
			}else if(stk.top().first == color){
				stk.top().second++;
			}else if(i % 2 == 1){
				pii item = stk.top();
				stk.pop();
				if(!stk.empty()){
					stk.top().second += item.second + 1;
				}else{
					stk.push(pii(color, item.second + 1));
				}
			}else{
				stk.push(pii(color, 1));
			}
		}
		int answer = 0;
		while(!stk.empty()){
			if(stk.top().first == 0){ answer += stk.top().second; }
			stk.pop();
		}
		cout << answer << endl;
	}
	return 0;
}