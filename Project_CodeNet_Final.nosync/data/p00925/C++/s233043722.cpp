#include <iostream>

using namespace std;

#define REP(i,n) for (int i=0; i<n; i++)

string str;
int j=0;

int calc_mult(){
	int num = str[j] - '0';
	j++;
	while(1){
		if (j>=str.size()){
			return num;
		}else if (str[j]=='+'){
			j++;
			return (num += calc_mult());
		}else{
			j++;
			num *= str[j] - '0';
			j++;
		}
	}
}

int calc_lr(){
	int ret=str[0] - '0';
	char last_op = '+';
	for (int i=1; i+1<str.size(); i++){
		last_op = str[i];
		i++;
		ret = last_op=='+' ? ret+(str[i]-'0') : ret*(str[i] - '0');	
	}
	return ret;
}

int main(){
	int bob;
	cin >> str >> bob;
	int mult=calc_mult(), lr = calc_lr();
	if (mult==bob){
		if (lr==bob){
			cout << "U" << endl;
		}else{
			cout << "M" << endl;
		}
	}else if (lr==bob){
		cout << "L" << endl;
	}else{
		cout << "I" << endl;
	}
	return 0;
}
