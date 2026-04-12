#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int a,b,c;
	cin >> a >> b >> c;
	int x = a*100+b*10+c;
	(x % 4) ? cout<<"NO" : cout<<"YES"; 
    return 0;
}
