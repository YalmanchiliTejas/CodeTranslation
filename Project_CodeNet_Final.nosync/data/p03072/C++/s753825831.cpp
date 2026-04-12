#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n,a,max,cou=1;
	cin >> n;
	cin >> a;
	max = a;
	n--;
	while(n--){
		cin >> a;
		if(a>=max){
			cou++;
			max = a;
		}
	}
	cout << cou <<endl;
    return 0;
}