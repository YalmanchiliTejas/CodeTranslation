#include <iostream>
using namespace std;
int n, m, j = 1, a[31], b[31], c[100];

int main(){
	char s;
	while(cin >> n >> s >> m, n+m){
		a[n] = m;
		b[m]++;
	}
	for(int i = 30;i >= 0;i--){
		if(b[i]){c[i] = j;j++;}
	}
	while(cin >> n){
		cout << c[a[n]] << endl;
	}
	return 0;
}