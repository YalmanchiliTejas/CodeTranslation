#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;


int main()
{
	string str;
    int n,k, i;

    cin >> n;
	cin >> str;
	cin >> k;

	for( i = 0; i < n; i++ ){
		if( str[i] != str[k-1] ){
			str[i] = '*';
		}
	}

	cout << str << endl;

    return 0;
}