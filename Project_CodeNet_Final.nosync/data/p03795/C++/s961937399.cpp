#include<iostream>
#include<string>
#include<algorithm>


using namespace std;

int main()
{
	int N;
	cin >> N ; 
	int x, y;

	x = 800 * N;
	y = N / 15*200;

	cout << x-y << endl;
    
	return 0;
}
