// 2011Í[à\I A. koukyoukoukokukikou

#include <iostream>
#include <string>

using namespace std;

int main(){
	string str;
	int a[26] = { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0 };
	while(cin >> str){
		if(str == "#") break;
		int res = 0, prev = a[str[0]-'a'];
		for(int i=1;i<str.size();i++){
			if(prev!=a[str[i]-'a']) res++;
			prev = a[str[i]-'a'];
		}
		cout << res << endl;
	}
}