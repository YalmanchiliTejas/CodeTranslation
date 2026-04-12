#include <bits/stdc++.h>
using namespace std;

string S;
int K;
int num[1001] = {0};
int keta;


int f(int p,int k){
	if(k < 0) return 0;
	if(k == 0) return 1;
	if(p <= 0) return 0;
	return f(p-1,k) + 9*f(p-1,k-1);
}

int solve(){
	int sm = 0;
	int k = K;
	for(int i = keta-1; i > 0; i--){
		if(num[i] != 0){
			sm += f(i,k) + (num[i]-1)*f(i,k-1);
			k--;
		}
	//	if(k < 0) k = 0;
	}
	if(k == 0){
		sm += 1;
	}
	if(k == 1){
		sm += num[0];
	}
	return sm;
}

int main(){
	cin >> S >> K;
	keta = S.size();
	for(int i = 0; i < S.size(); i++){
		num[S.size()-1-i] = S[i] - '0';
	}

	cout << solve() << endl;

	return 0;
}
