#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#define LL long long
using namespace std;

string s[10];
int h, w, cnt;

int main() 
{
	cin >> h >> w;
	for(int i = 1; i <= h; i++) cin >> s[i];
	
	for(int i = 1; i <= h; i++)
		for(int j = 0; j < w; j++)
		{
			if(s[i][j] == '#') cnt++;
		}
	cout << (cnt == h+w-1 ? "Possible" : "Impossible") << endl;
	return 0;
}