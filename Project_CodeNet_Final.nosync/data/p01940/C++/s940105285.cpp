#include <iostream>
#include <string>
#include <vector>
using namespace std;

string T,P;
vector<int> vec;

main(){
	cin >> T >> P;
	vec = vector<int>(P.size(),-1);
	int ip = 0;
	for(int i = 0; i < T.size() && ip < P.size(); i++){
		if(T[i] == P[ip]){
			vec[ip++] = i;
		}
	}
	if(vec[P.size()-1] < 0){
		cout << "no" << endl;
		return 0;
	}
	ip = P.size() - 1;
	for(int i = T.size() - 1; i >= 0; i--){
		if(T[i] == P[ip]){
			if(i != vec[ip--]){
				cout << "no" << endl;
				return 0;
			}
		}
	}
	cout << "yes" << endl;

	return 0;
}