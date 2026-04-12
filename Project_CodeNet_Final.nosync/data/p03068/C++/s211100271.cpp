#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <math.h>
//#include <istream>
//#include <sstream>
using namespace std;

int main()
{
	string S;
	int N;
	int K;
	char ss;
	cin >> N;
	cin >> S;
	cin >> K;
	ss = S[K-1];

	for (int i = 0; i < N; i++)
	{
		if (S[i] != ss) {
			S[i] = '*';
		}
	}
	cout << S << endl;

}