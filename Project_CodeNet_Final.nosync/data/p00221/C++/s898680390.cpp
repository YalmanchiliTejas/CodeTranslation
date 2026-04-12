#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(){
	int n,m,k,j,tmp,cnt;
	bool c[1000],f;
	string input[10000],str;
	while(cin >> m >> n,m){
		cnt = 0;
		f = true;
		for(int i = 0;i < 1000;++i){
			c[i] = true;
		}
		for(int i = 0;i < n;++i){
			cin >> input[i];
		}
		j = k = 0;
		while(j != n && f){
			if(c[k]){
				stringstream ss;
				tmp = j + 1;
				str = "";
				if(tmp % 3 && tmp % 5) ss << tmp;
				if(tmp % 3 == 0) ss << "Fizz";
				if(tmp % 5 == 0) ss << "Buzz";
				ss >> str;
			//	cout << str << " " << input[j] << endl;
				c[k] = (str == input[j]);
				if(!c[k]) ++cnt;
				++j;
			}
			++k;
			if(k == m) k = 0;
			if(m - cnt == 1) f = false;
		}
		j = 0;
		for(int i = 0;i < m;++i){
			if(c[i]){
				if(j) cout << " ";
				cout << i + 1;
				++j;
			}
		}
		cout << endl;
	}
	return 0;
}