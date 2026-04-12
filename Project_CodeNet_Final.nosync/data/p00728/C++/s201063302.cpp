#include <iostream>

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

using namespace std;

int main(void)
{
	while(1){
		int n;
		cin >> n;
		if (n == 0){
			break;
		}
		int s, sum=0, maxi, mini;
		cin >> s;
		maxi = s;
		mini = s;
		sum += s;
		for(int i=1;i<n;i++){
			cin >> s;
			maxi = max(maxi, s);
			mini = min(mini, s);
			sum += s;
		}
		sum -= (maxi + mini);
		cout << sum/(n-2) << endl;
	}
	return 0;
}
