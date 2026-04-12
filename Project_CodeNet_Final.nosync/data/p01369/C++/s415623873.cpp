#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
bool l[180];
string str;
int main(){
	for(int i = 0;i < 11;i++){
		l["yuiophjklnm"[i]] = true;
	}
	while(cin >> str, str != "#"){
		bool pos = l[str[0]];
		int res = 0;
		for(int i = 1;i < str.size();i++){
			if(l[str[i]] ^ pos)res++;
			pos = l[str[i]];
		}
		cout << res << endl;
	}
	return 0;
}