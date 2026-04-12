#include <bits/stdc++.h>
using namespace std;

int main()
{
	int R, G, B;
	cin >> R >> G >> B;
	int RGB = 100*R + 10*G + B;
	if(RGB%4 == 0){
	cout << "YES" << endl;
	}
	else
	{
	cout << "NO" << endl;
	}	
}