#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <cstring>
#include <deque>
#include <cstdio>
#include <cmath>
#include <complex>
#include <iostream>
#include <iterator>

using namespace std;

#define reep(i,f,t) for(int i=f ; i<int(t) ; ++i)
#define rep(i,n) reep(i, 0, n) 

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

int main()
{
	int data[6];
	for(;;){
		int sum = 0;
		rep(i, 6){
			scanf("%d", &data[i]);
			sum += data[i];
		}
		if(sum == 0)
			break;
		
		int d[3] = {data[0]+data[3], data[1]+data[4], data[2]+data[5]};
		int mini = min(d[0], min(d[1], d[2]));
		int ans = mini;
		int rem[3];
		rep(i, 3){
			ans += (d[i] - mini) / 3;
			rem[i] = (d[i] - mini) % 3;
		}
		sort(rem, rem+3);
		if(rem[0] == 0 && rem[1] == 2 && mini >= 1)
			ans++;
		printf("%d\n", ans);
	}
	
	return 0;
}