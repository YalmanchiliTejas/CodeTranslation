#include <iostream>
#define llint long long

using namespace std;

llint K;
llint comb[605];
llint cnt[605];

int main(void)
{
	cin >> K;
	
	comb[0] = 1;
	for(int i = 1; i < 600; i++){
		comb[i] = comb[i-1] * (i+7) / i;
	}
	
	for(int i = 599; i >= 0; i--){
		cnt[i] = K / comb[i];
		K %= comb[i];
	}
	
	for(int i = 0; i < 600; i++){
		cout << "FESTIVA";
		for(int j = 0; j < cnt[i]; j++) cout << "L";
	}
	cout << endl;
	return 0;
}