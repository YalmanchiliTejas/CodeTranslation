#include <iostream>
using namespace std;

int main()
{
	int view = 0;
	int max_current = 0;
	
	int N;
	cin >> N;
	
	int H;
	for (int i = 0; i < N; i++) {
		cin >> H;
		if (max_current <= H){
			max_current = H;
			view++;
		}
	}
	
	cout << view << endl;
	
	return 0;
}