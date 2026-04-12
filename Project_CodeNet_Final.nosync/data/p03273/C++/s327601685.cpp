#include <iostream>
#include <vector>
#include <tuple>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <limits>
#include <unordered_map>

using namespace std;
using str = string;

#define rep(a,l,r) for(int a=(l);a<(r);a++)
#define get cin>>
#define put cout<<

void run() {

	int h; get h;
	int w; get w;

	vector<str> rows(h);

	for(auto& row:rows){
		get row;
	}

	auto it = rows.begin();
	while(it!=rows.end()){
		if(count(it->begin(), it->end(),'#') == 0){
			rows.erase(it);
		} else {
			++it;
		}
	}

	vector<bool> columns(w,false);
	rep(i,0,w){
		for(auto& row: rows){
			if(row[i] == '#'){
				columns[i] = true;
				break;
			}
		}
	}

	for(auto& row: rows){
		rep(i,0,w){
			if(columns[i]){
				put row[i];
			}
		}
		put endl;
	}

}
int main() {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);run();return 0;}
