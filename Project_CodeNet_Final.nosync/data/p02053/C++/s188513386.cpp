#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;
vector<int> v[1010];
vector<pair<int,int>> u;
int main(){
	int i,j,h,w;
	cin >> h >> w;
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			char c; cin >> c;
			if(c=='B'){
				v[i].push_back(j);
			}
		}
	}
	for(i=0;i<h;i++){
		sort(v[i].begin(),v[i].end());
	}
	for(i=0;i<h;i++){
		if(v[i].size()>=1){
			u.push_back({i,v[i][0]});
			u.push_back({i,v[i].back()});
		}
	}
	int mx = 0;
	for(i=0;i<u.size();i++){
		for(j=0;j<u.size();j++){
			mx = max(mx,abs(u[i].first - u[j].first) + abs(u[i].second - u[j].second));
		}
	}
	cout << mx << endl;
}
