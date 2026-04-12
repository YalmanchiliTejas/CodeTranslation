#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(){

	int sum, top, front, right, n, tmp;
	string op;
	map<string, int> mp;
	
	mp.insert(make_pair("North", 1));
	mp.insert(make_pair("East", 2));
	mp.insert(make_pair("South", 3));
	mp.insert(make_pair("West", 4));
	mp.insert(make_pair("Right", 5));
	mp.insert(make_pair("Left", 6));
	
	while(cin >> n){
		if(n == 0) break;
		
		sum = 1;
		top = 1;
		front = 2;
		right = 3;
		
		for(int i=0; i<n; i++){
			cin >> op;
			switch(mp[op]){
 				case 1: tmp = top; top = front; front = 7 - tmp; break;
				case 2: tmp = top; top = 7 - right; right = tmp; break;
				case 3: tmp = top; top = 7 - front; front = tmp; break;
				case 4: tmp = top; top = right; right = 7 - tmp; break;
				case 5: tmp = front; front = right; right = 7 - tmp; break;
				case 6: tmp = front; front = 7 - right; right = tmp; break;
			}
			sum += top;
		}
		
		cout << sum << endl;
	}
	
	return 0;

}