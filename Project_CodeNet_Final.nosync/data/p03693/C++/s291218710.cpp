#include<iostream>
#include<string>
#include<typeinfo>
#include<vector>
#include<algorithm>
#include<map>
#include<iomanip>
using namespace std;
int main()
{
	int a,b,c;
	cin >> a >> b >> c;
  	int n = a*100+b*10+c;
  	cout << (n%4 ? "NO" : "YES") << endl;
	return 0;
}
