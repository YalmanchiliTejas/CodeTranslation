#include<iostream>
#include<array>
#include<string>
using namespace std;

int main() {
	int num;
	cin >> num;
	int mou;
	int old = 0;
	int see = 0;
	int f = 0;
	int loop = 0;
	while (num--) {
		cin >> mou;
		if (mou >= old && mou >= f)
		{
			see++;
		}
		if (loop == 0) {
			f = mou;
		}
		if(mou>=old){
			old = mou;
		}
		loop++;
	}
	cout << see << endl;
}