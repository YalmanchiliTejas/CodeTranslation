#include <iostream>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF = 10000000;
using namespace std;
typedef long long  ll;
/** Problem0195 : What is the Most Popular Shop in Tokaichi? **/
int main()
{
	string list = "ABCDE";
	int s1, s2, max=0, i=0;
	char maxN;
	while (1) {
		cin >> s1 >> s2;
		if (s1 == 0 && s2 == 0)
			break;
		
		if (max < s1+s2) {
			max = s1 + s2;
			maxN = list[i%5];
		}
		
		if (i%5==4) {
			cout << maxN << " " << max << endl;
			max = 0;
		}
		i++;
	}
	return 0;
}