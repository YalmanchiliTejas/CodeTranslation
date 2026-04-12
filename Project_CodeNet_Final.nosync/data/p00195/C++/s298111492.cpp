#include<iostream>
using namespace std;
int main()
{
	char al[6] = { "ABCDE" };
	while (true){
		int p, a, b, max = 0;
		for (int i = 0; i < 5; i++){
			cin >> a >> b;
			if (a == 0 && b == 0)return 0;
			if (max < a + b){
				max = a + b;
				p = i;
			}
		}
		cout << al[p] << " " << max << endl;
	}
}