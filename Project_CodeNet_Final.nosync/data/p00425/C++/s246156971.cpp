#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int n;
	int top, front, right, sub, res;
	string order;
	
	while(true){
		cin >> n;
		if(n == 0) return 0;
		
		top = 1; front = 2; right = 3;
		res = 1;
		
		for(int i = 0; i < n; i++){
			cin >> order;
			if(order == "North"){
				sub = 7 - top;
				top = front;
				front = sub;
			}
			else if(order == "South"){
				sub = 7 - front;
				front = top;
				top = sub;
			}
			else if(order == "East"){
				sub = 7 - right;
				right = top;
				top = sub;
			}
			else if(order == "West"){
				sub = 7 - top;
				top = right;
				right = sub;
			}
			else if(order == "Right"){
				sub = 7 - front;
				front = right;
				right = sub;
			}
			else if(order == "Left"){
				sub = 7 - right;
				right = front;
				front = sub;
			}
			
			res += top;
		}
		
		cout << res << endl;
	}
}