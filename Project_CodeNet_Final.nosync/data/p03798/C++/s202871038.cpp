#include <iostream>
#include <string>
using namespace std;

int mod = 1000000007;
	bool ii[100000],oo[100000];

	int N;
void p(){
	string str;
	for(int i = 0;i < N;i++){
		if(oo[i]) str += 'S';
		else str += 'W';
	}
	cout << str;
}

bool r(bool s,bool p,bool a){
	return (s != (p != a));
}
int main() {
	// your code goes here
	string in,out;
	cin >> N;
	cin >> in;
	for(int i = 0;i < N;i++){
		ii[i] = (in[i] == 'o');
	}
	oo[0] = true;
	oo[1] = true;
	for(int i = 2;i < N;i++){
		oo[i] = r(ii[i-1],oo[i-1],oo[i-2]);
	}
	if(oo[0] == r(ii[N-1],oo[N-1],oo[N-2]) && oo[1] == r(ii[0],oo[0],oo[N-1])){
		p();
		return 0;
	}
	oo[0] = false;
	oo[1] = true;
	for(int i = 2;i < N;i++){
		oo[i] = r(ii[i-1],oo[i-1],oo[i-2]);
	}
	if(oo[0] == r(ii[N-1],oo[N-1],oo[N-2]) && oo[1] == r(ii[0],oo[0],oo[N-1])){
		p();
		return 0;
	}
	oo[0] = true;
	oo[1] = false;
	for(int i = 2;i < N;i++){
		oo[i] = r(ii[i-1],oo[i-1],oo[i-2]);
	}
	if(oo[0] == r(ii[N-1],oo[N-1],oo[N-2]) && oo[1] == r(ii[0],oo[0],oo[N-1])){
		p();
		return 0;
	}
	oo[0] = false;
	oo[1] = false;
	for(int i = 2;i < N;i++){
		oo[i] = r(ii[i-1],oo[i-1],oo[i-2]);
	}
	if(oo[0] == r(ii[N-1],oo[N-1],oo[N-2]) && oo[1] == r(ii[0],oo[0],oo[N-1])){
		p();
		return 0;
	}
	cout << -1 << endl;
	return 0;
}