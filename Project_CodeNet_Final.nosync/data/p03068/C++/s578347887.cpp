#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	
	string str;
	cin >> str;
	
	int M;
	cin >> M;
	
//		cout << str.at(M-1) <<endl;
	
	for(int i=0;i<N;i++){
		if(!(str.at(M-1)==str.at(i))){
			str.at(i)='*';
		}
	}
	
	cout << str <<endl;
	
	
}