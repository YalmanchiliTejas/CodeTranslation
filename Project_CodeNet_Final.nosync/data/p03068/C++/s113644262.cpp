#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define $ template <tyepename T>

int main(){
    ios::sync_with_stdio(false);
	int n;
	string st;
	int k;
	cin >> n >> st >> k;
	for(int i=0; i<n; i++){
		if(st[k-1]!=st[i])
			cout << "*";
		else
			cout << st[i];
	}
    cout << endl;
}