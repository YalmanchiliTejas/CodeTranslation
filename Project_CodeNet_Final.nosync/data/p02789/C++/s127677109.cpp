#include<iostream>
using namespace std;
int main()
{
	int N, M;
	cin >> N >> M;
	if ((N >= 1 && N <= 100) && (M >= 0 && M <= N))
	{
		if (M==N)
			cout <<"Yes"<< endl;
		else
			cout <<"No"<< endl;
	}
	else
		cout << "Wrong inputs" << endl;
	return 0;
}