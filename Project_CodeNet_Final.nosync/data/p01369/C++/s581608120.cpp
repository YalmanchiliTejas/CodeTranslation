#include <iostream>
using namespace std;

int cnt;
bool isleft, now;
string leftkey = "qwertasdfgzxcvb";

int main(void){
	while(true){
		cnt = 0;
		string str;
		cin >> str;
		if(str == "#")	break;
	
		if(leftkey.find(str[0]) != string::npos){
			now = true;
		}else{
			now = false;
		}

		for(int i = 1; i < str.size(); i++){
			if(leftkey.find(str[i]) != string::npos){
				isleft = true;
			}else{
				isleft = false;
			}
			if(isleft != now)	cnt++;
			now = isleft;
		}

		cout << cnt << endl;
	}
	return 0;
}