#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> vec(n);
	for ( int i = 0 ; i < n ; i++ ) cin >> vec[i];
	
	int cnt = 1 ;
	for ( int i = 1 ; i < n ; i++ )
	{
		int j = i;
		for ( j = i ; j > 0 ; j-- )
			if ( vec[i] < vec[j] ) break; 
		if ( j == 0 && vec[i] >= vec[0] ) cnt++;
	}

	cout << cnt << endl;

	return 0;
}
