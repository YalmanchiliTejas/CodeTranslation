#include <iostream>
#include <vector>
using namespace std;

int main(){
	int N,K;
	string str;
	cin >> N;
	cin >> str;
	cin >> K;

	for(int i=0;i<N;i++){
		if(str[i]!=str[K-1]){
			str[i]='*';
		}
	}

	cout << str << "\n";

}

