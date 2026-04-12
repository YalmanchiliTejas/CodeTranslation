#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int ll;
int main(){
	int N;
	int X[200000], forsort[200000];
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> X[i];
		forsort[i] = X[i];
	}
	sort(forsort, forsort + N);
	int m1 = forsort[N / 2 - 1], m2 = forsort[N / 2];
	for(int i = 0; i < N; i++){
		if(X[i] == m1) cout << m2 << endl;
		else if(X[i] == m2) cout << m1 << endl;
		else if(X[i] > m2) cout << m1 << endl;
		else cout << m2 << endl;
	}
	return 0;
}