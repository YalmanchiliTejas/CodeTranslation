#include "stdio.h"
#include "math.h"
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <iostream>

using namespace std;
/** Problem0078 : Magic Square **/
int main()
{
	int sq[15][15], n, oldX, oldY;
	
	while (cin >> n && n != 0) {
		memset(sq, 0, sizeof(sq));
		
		sq[n/2][n/2+1] = 1;
		oldX = n/2; oldY = n/2+1;
		
		for (int i=2;i<=n*n;i++) {
			if (sq[(oldX+1)%n][(oldY+1)%n] == 0) {
				sq[(oldX+1)%n][(oldY+1)%n] = i;
				oldX = (oldX+1)%n; oldY = (oldY+1)%n;
			} else {
				sq[oldX][(oldY+2)%n] = i;
				oldY = (oldY+2)%n;
			}
			
		}
		
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				cout << setw(4) << right << sq[j][i];
			}
			cout << endl;
		}
	}
	return 0;
}