#include <iostream>
#include    <algorithm>
#include <cmath>
#include <cstdio>
#include  <cstdlib>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)n;i++)
typedef long long lint;
#define SZ(x) ((int)(x).size())
int main()
{
	int n;
	int h[100];
	cin >> n;
	rep(i, n) cin >> h[i];
	
	int cnt = 1;
	
	for (int i = n-1; i > 0; i--) {
		bool flg = false;
		for (int j = 0; j < i; j++) {
			
			if (h[i] < h[j]) {
				flg = true;
				break;	
			}
		}
		if (!flg) cnt++;
	}
	cout << cnt<< endl;


	return 0;
}
