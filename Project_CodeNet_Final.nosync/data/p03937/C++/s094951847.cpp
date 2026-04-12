#include	<bits/stdc++.h>
using	namespace	std;

// int/long:		-2147483648 - 2147483648 (-2^31 <= int < 2^31)
// long/long long:	-9223372036854775808 - 9223372036854775807 (-2^63 <= long < 2^63)
#define	INF (1<<29)
//536870912

#define	MOD 1000000007

int	main() {
	int H, W;
	cin >>H >>W;
	vector<vector<int>> A(H+1, vector<int> (W+1, 0));
	int S=H+W-1;
	for (int i=0; i<H; i++)
		for (int j=0; j<W; j++) {
			char c;
			cin >>c;
			if ('#'==c) {
				A.at(i).at(j)=1;
				S--;
			}
		}
	if (0!=S) {
		cout <<"Impossible" <<endl;
		return 0;
	}
	vector<vector<int>> q;
	q.push_back({0, 0});
	int ix=0;
	while (ix<q.size()) {
		int x=q.at(ix).at(0);
		int y=q.at(ix).at(1);
		if ((x==H-1)&&(y==W-1)) {
			cout <<"Possible" <<endl;
			return 0;
		}
		if(1==A.at(x).at(y+1))
			q.push_back({x, y+1});
		if(1==A.at(x+1).at(y))
			q.push_back({x+1, y});
		ix++;
	}
	cout <<"Impossible" <<endl;
	return 0;
}

