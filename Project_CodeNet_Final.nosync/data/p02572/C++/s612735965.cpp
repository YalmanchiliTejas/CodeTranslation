#include<bits/stdc++.h>
#define MM 1000000007
using namespace std;
long long rsk[200002];
int main(void){
	int n,i;
	long long x,sum;
	int box[200001];
	cin >> n;
	rsk[0] = 0;
	for(i = 0; i < n; i++){
		cin >> box[i];
		rsk[i + 1] = rsk[i] + box[i];
	}
	sum = 0;
	for(i = 0; i < n - 1; i++){
		x = (rsk[n] - rsk[i + 1]) % MM;
		sum += x * box[i];
		sum %= MM;
	}
	cout << sum % MM << endl;
	return 0;
}