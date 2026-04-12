#include<iostream>
using namespace std;
#include <vector>  
#include<algorithm>

int main()
{
	int N,M;
	string result = "Yes";

	cin >>N>>M;

	if (N != M)result = "No";

	cout << result<<endl;
}

