#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Max = 1e3 + 7;
char lst[Max][Max];
int ls[Max][Max];

int main()
{
	ll x,y,z;
	cin >> x >> y >> z;
	cout << (x - z) / (z + y);

}