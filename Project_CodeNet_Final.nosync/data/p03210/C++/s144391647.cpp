#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;

int main(){
	int a;
	cin >> a;
	if (a == 3 || a == 5 || a == 7){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
	return 0;
}