#include <iostream>
#include <cstring>
using namespace std;

char Right[11] = {'y','u','i','o','p','h','j','k','l','n','m'};

int main(){
	string str;
	while(cin >> str){
		if(str[0] == '#') break;
		int ans = 0;
		bool position = false;
		for(int i = 0; i < 11; i++){
			if(Right[i] == str[0]){
				position = true;
				break;
			}
		}
		for(int i = 1; i < str.size(); i++){
			bool now = false;
			for(int j = 0; j < 11; j++){
				if(Right[j] == str[i]){
					now = true;
					break;
				}
			}
			if(position != now){
				ans++;
				position = now;
			}
		}
		cout << ans << endl;
	}
}