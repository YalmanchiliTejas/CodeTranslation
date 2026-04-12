#include <bits/stdc++.h>
using namespace std;
int N;
int d[1000000];
string checkprev(){
	int canhop=1;
	for(int i = N-1;i>0;i--){
		canhop--;
		canhop = max(canhop,d[i]/10);
		if(canhop ==0)
			return "no";
	}
	return "yes";
}
string checkfront(){
	int canhop=1;
	for(int i = 0;i<N;i++){
	canhop--;
	canhop = max(canhop,d[i]/10);
	if(canhop ==0)
		return "no";
	}
	return checkprev();
}
int main(){
	cin >> N;
	for(int i = 0;i<N;i++){
		cin >> d[i];
	}
	cout << checkfront()<<endl;
	return 0;
}
