
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <random>
#include <queue>

using namespace std;


int main()
{
	int  N;
	cin >> N;

	int ans  = 1;
	int u_h = 1e9;

	int h;
	cin >> u_h;
	for (int ni = 1; ni < N; ni++){
		cin >> h;
		if (h >= u_h){
			ans++;
			u_h = h;
		}
	}


	printf("%d", ans);

	return 0;
}

