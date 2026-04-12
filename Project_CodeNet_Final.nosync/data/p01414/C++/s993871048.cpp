#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <climits>
#include <queue>
using namespace std;

int main()
{
	int n;
	cin >> n;

	set<int> stamp;
	for(int i=0; i<n; ++i){
		int h, w;
		cin >> h >> w;
		for(int j=-3; j<4; ++j){
			for(int k=-3; k<4; ++k){
				bitset<16> bs;
				for(int y=j; y<j+h; ++y){
					for(int x=k; x<k+w; ++x){
						if(0 <= y && y <4 && 0 <= x && x < 4)
							bs[y*4+x] = true;
					}
				}
				if(bs.any())
					stamp.insert(bs.to_ulong());
			}
		}
	}

	vector<bitset<16> > color(3);
	for(int i=0; i<16; ++i){
		char c;
		cin >> c;
		if(c == 'R')
			color[0][i] = true;
		else if(c == 'G')
			color[1][i] = true;
		else
			color[2][i] = true;
	}

	vector<int> memo(1<<16, -1);
	queue<int> q;
	memo[0] = 0;
	q.push(0);
	for(;;){
		bitset<16> bs = q.front();
		q.pop();

		set<int>::iterator it;
		for(it=stamp.begin(); it!=stamp.end(); ++it){
			for(int i=0; i<3; ++i){
				bitset<16> bs2 = color[i] & bitset<16>(*it);
				if(bs2.none())
					continue;
				bs2 |= bs & ~bitset<16>(*it);
				if(memo[bs2.to_ulong()] == -1){
					memo[bs2.to_ulong()] = memo[bs.to_ulong()] + 1;
					q.push(bs2.to_ulong());
					if(bs2.all()){
						cout << memo[bs2.to_ulong()] << endl;
						return 0;
					}
				}
			}
		}
	}
}