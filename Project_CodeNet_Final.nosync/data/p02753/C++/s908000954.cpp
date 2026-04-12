#include <iostream>
#include <string>

using namespace std;

int main(){
	int ac=0,bc=0;
	for(int i=0;i<3;++i){
		char c;
		cin >> c;
		if(c == 'A')ac++;
		else bc++;
	}
	if(ac == 0||bc == 0)cout << "No" << endl;
	else cout << "Yes" << endl;
}