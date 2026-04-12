#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<cmath>
#include<stack>
//#include<stdlib.h>
using namespace std;
int main() {
	int i,t=0,s=0;
	cin >> i;
	vector<int>h(i);
	for (int a = 0; a < i; a++) { cin >> h[a]; }
	for (int a = 0; a < i; a++)
	{
		if (t <= h[a]) { t = h[a]; s++; }
	}
	cout << s;
	return 0;
}