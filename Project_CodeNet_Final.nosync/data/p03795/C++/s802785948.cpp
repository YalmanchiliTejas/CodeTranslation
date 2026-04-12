#include<iostream>
#include<string>
#include<typeinfo>
#include<vector>
#include<algorithm>
#include<map>
#include<iomanip>
using namespace std;
typedef long long int ll;
int main()
{
	int n;
  	cin >> n;
  
	cout << n*800 - (n/15)*200 << endl;

	return 0;
}