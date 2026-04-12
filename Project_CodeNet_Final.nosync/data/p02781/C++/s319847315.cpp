#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <iterator>
#include <cmath>
#include <set>
#include <deque> 
#include <string>


using namespace std;

char n[110];
int szN;
int k;

long long f[110][5];

void init()
{
//	f[0][0] = 1;
//	f[1][0] = 1;
//	f[1][1] = 9;
//	f[2][0] = 1;
//	f[2][1] = 18;
//	f[2][2] = 81;
//	f[3][0] = 1;
//	f[3][1] = 27;
//	f[3][2] = 243;
//	f[3][3] = 729;

	f[0][0] = 1;
	f[1][0] = 1;
	f[1][1] = 9;
	f[2][0] = 1;
	f[2][1] = 18;
	f[2][2] = 90;
	f[3][0] = 1;
	f[3][1] = 27;
	f[3][2] = 243;
	f[3][3] = 729;
	
	for (int i = 4 ; i <= 100 ; i++) {
		f[i][0] = 1;
		f[i][1] = 9 + f[i-1][1];
		f[i][2] = i * (i - 1) / 2 * 9 * 9;
		f[i][3] = i * (i - 1) * (i - 2) / 6 * 9 * 9 * 9;
	}

}
		
int main()
{
	init();	
	
	scanf("%s\n", n);
	szN = strlen(n);
		
	scanf("%d", &k);
	
	long long count = 0;
	int level = szN;
	int curK = k;
	int curOnes = 0;
	for (int i = 0 ; i < szN ; i++, level--) {
		if (curK <= 0) {
			break;
		}
		
		long long ans = 0;
		int cc = n[i] - '0';
		if (cc == 0) {
			continue;
		} else {
			curOnes++;
			if (curOnes == k)
				count++;
			ans = ans + f[level - 1][curK];
			for (int j = 1 ; j < cc ; j++) {
				ans = ans + f[level - 1][curK - 1];
			}
			curK--;
		}
		
		
		count = count + ans;
	}
	
	
	
	printf("%lld\n", count);
	
	
	return 0;
}
