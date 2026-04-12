#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 2 * 1e5 + 10;
int a[MAXN];
int n;

int main(){
	cin >> n;
	for(int i = 1 ; i <= n ; ++ i)
		cin >> a[i];
	if(n % 2 == 0){
		for(int i = n ; i >= 2 ; i -= 2)
			cout << a[i] << " ";
		for(int i = 1 ; i <= n ; i += 2)
			cout << a[i] << " ";
		cout << endl;
	}
	else{
		for(int i = n ; i >= 1 ; i -= 2)
			cout << a[i] << " ";
		for(int i = 2 ; i <= n ; i += 2)
			cout << a[i] << " ";
		cout << endl;
	}
	return 0;
}