#include <algorithm>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define pii pair <int, int>
#define pb push_back
#define ll long long
#define ss second
#define ff first
#define N 500010

using namespace std;

int a, b, c;

int main()
{
	cin >> a >> b >> c;
	
	if((b*10+c)%4 == 0)
		cout << "YES";
	else
		cout << "NO";
}