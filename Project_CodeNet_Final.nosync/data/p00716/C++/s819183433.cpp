#include <iostream>
#include<cstdio>
#include<algorithm>
#include<math.h>
using namespace std;

int main()
{
	int a;
	cin >> a;
	for (int b = 0; b < a; b++) {
		int c, d, e;
		cin >> c >> d >> e;
		int MAX = c;
		for (int f = 0; f < e; f++) {
			double g, h, s;
			cin >> g >> h >> s;
			if (g) {
				double j = c;
				for (int i = 0; i < d; i++) {
					j *= (1 + h);
					j = (int)j;
					j -= s;
				}
				MAX = max(MAX,(int)floor(j));
			}
			else {
				double j = c, o = 0;
				for (int i = 0; i < d; i++) {
					o += floor(j*h);
					j -= s;
				}
				MAX = max(MAX,int(o+j));
			}
		}
		cout << MAX << endl;
	}
}