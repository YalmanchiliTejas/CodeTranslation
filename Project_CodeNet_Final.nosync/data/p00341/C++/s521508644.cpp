#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int l[12];
	for (int i = 0; i < 12; i++){
		cin >> l[i];
	}
	sort(l, l + 12);
	if (l[0] == l[1] && l[1] == l[2] && l[2] == l[3]) {
		if (l[4] == l[5] && l[5] == l[6] && l[6] == l[7]) {
			if (l[8] == l[9] && l[9] == l[10] && l[10] == l[11]) {
				cout << "yes";
			}
			else
			{
				cout << "no";
			}
		}
		else { 
			cout << "no"; 
		}
	}
	else
	{
		cout << "no";
	}
	cout << endl;
}