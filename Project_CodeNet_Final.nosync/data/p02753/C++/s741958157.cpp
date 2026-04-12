#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	string S;
	cin>>S;
	int countA=0,countB=0;
	for(int i=0; i<S.size(); i++){
		if(S[i]=='A') countA++;
		else          countB++;
	}
	if(countA==3||countB==3) cout<<"No"<<endl;
	else                     cout<<"Yes"<<endl;
}