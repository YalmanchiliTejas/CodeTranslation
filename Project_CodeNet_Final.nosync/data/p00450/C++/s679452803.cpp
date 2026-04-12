#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <stack>
 
#define rep(i, n) for(int i = 0; i < (n); i++)
#define MP make_pair
#define X first
#define Y second
 
using namespace std;
 
typedef vector<int> vi;
typedef pair<int, int> P;

const int INF = 1<<27;

int main(){
	int n;
	while(cin >> n, n){
		vector<P> stone;
		for(int i = 1; i <= n; i++){
			int c;
			cin >> c;
			if(i%2){
				if(stone.empty() || (stone.back().first != c)){
					stone.push_back(MP(c, 1));
				}else{
					stone.rbegin()->second++;
				}
			}else{
				if(c == stone.rbegin()->first){
						stone.rbegin()->second++;
				}else{
					int s = stone.rbegin()->second+1;
					stone.pop_back();
					if(stone.empty()){
						stone.push_back(MP(c, s));
					}else{
						stone.rbegin()->second+=s;
					}
				}
			}
		}
		int ans = 0;
		rep(i, stone.size()){
			if(stone[i].first == 0) ans += stone[i].second;
		}
		cout << ans << endl;
	}
 
    return 0;
}