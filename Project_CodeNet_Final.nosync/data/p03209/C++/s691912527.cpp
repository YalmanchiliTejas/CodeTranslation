#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	long x, havepati = 0;
	cin >> n >> x;
	long pati = (long)pow(2.0, n + 2) - 3;
	if (n == 0) {
		cout << 1 << endl;
		return 0;
	}
	while (pati >5) {
		if (x * 2 == pati + 1) {
			cout << havepati + (long)pow(2.0, n) - 1 + 1 << endl;
			return 0;
		}
		else if (x >= pati - 1) {
			cout << havepati + (long)pow(2.0, n + 1) - 1 << endl;
			return 0;
		}
		else if (x * 2 > pati + 1) {
			havepati += (long)pow(2.0, n) - 1 + 1;
			x -= (pati + 1) / 2;
			n--;
			pati = (pati + 3) / 2 - 3;
		}
		else {
			x--;
			n--;
			pati = (pati + 3) / 2 - 3;
		}
	}
  	if(x!=0)
	cout << (x<5? havepati + x - 1 : havepati + 3)<< endl;
	else
      	cout << havepati << endl;

}