#include <iostream>
#include <vector>
#include <cmath>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define SZ(x) ((int)(x).size())
using ll = long long;

using namespace std;

int main(){
	/*int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		int x;
		cin >> x;
		if(cin.eof())	break;	
		a[i]=x;
	}*/
	
	int x;
	cin >> x;
       	if(x == 3 || x == 5 || x == 7){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}	
	
	
	return 0;
}
