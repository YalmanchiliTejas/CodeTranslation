#include <bits/stdc++.h>

#define INF INT_MAX
typedef long long ll;

using namespace std;

int main(void){
	string s;
	cin >> s;

	bool flag = false;
	for(int i = 0;i < s.size() - 1;i++){
		if(s[i] == 'A' && s[i+1]== 'C'){
			flag = true;
		}
	}

	if(flag){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;
}