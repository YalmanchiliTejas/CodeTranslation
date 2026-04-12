#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef pair<int,int> P;
typedef pair<P,string> PP;

int main(void)
{

	int n;
	bool k = false;

	while(cin >> n,n){
		if(k)
			cout << endl;
	int win,lost,draw;
	PP team[10] = {};
	for(int i = 0; i < n; i++){
		cin >> team[i].second;
		cin >> win >> lost >> draw;
		team[i].first.first = win*3+draw;
		team[i].first.second= 10-i;
	}
	sort( team, team+10 );

	for(int i = 9; 10-i <= n; i--)
		cout << team[i].second << ',' << team[i].first.first << endl;


		k = 1;
	}


	return 0;
}