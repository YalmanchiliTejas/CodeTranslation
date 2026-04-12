#include<iostream>
#include<string>

using namespace std;

#define LEFT 1
#define RIGHT 0

int main(){

	string data = ("qwertasdfgzxcvb");
	int cnt;
	string inp;
	int f;

	while (1){

		cin >> inp;
		if (inp == "#") break;

		cnt = 0;
		if (data.find(inp[0]) != -1) f = LEFT;
		else f = RIGHT;

		for (int i = 1; i < inp.size(); i++){
			if (data.find(inp[i]) != -1){
				if (f == RIGHT){
					cnt++;
					f = LEFT;
				}
			}
			else if (f == LEFT){
				cnt++;
				f = RIGHT;
			}
		}

		cout << cnt << endl;

	}
}