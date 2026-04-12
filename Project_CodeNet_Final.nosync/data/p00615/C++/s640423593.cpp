#include <iostream>
#include <algorithm>

using namespace std;

int main( void )
{
	int n, m;
	int map[20000];
	while(cin >> n >> m, n | m) {
		int nm = n + m;
		for(int i=0; i < nm; ++i)
			cin >> map[i];
		sort(map, map+nm);
		int Max = map[0];
		--nm;
		for(int i=0; i < nm; ++i)
			Max = max(Max, map[i+1]-map[i]);
		cout << Max << endl;
	}
	return 0;
}