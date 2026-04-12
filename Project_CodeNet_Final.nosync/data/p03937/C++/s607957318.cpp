#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<bitset>
#include<queue>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
typedef long long ll;
typedef pair<int,int> P;

int main(){
	int h,w;
	cin >> h>>w;
	char a;
	vector<P> v;
	rep(i,h){
		rep(j,w){
			cin >> a;
			if (a == '#'){
				v.push_back(P(i,j));
			}
		}
	}
	bool flag = 0;
	rep(i,v.size()-1){
		if (((v[i].first+1==v[i+1].first)&&(v[i].second==v[i+1].second))||((v[i].first==v[i+1].first)&&(v[i].second+1==v[i+1].second))){
			continue;
		}
		else {
			flag = 1;
			break;
		}
	}
	if (flag){
		cout << "Impossible" << endl;
	}
	else {
		cout << "Possible" <<endl;
	}
	return 0;
}

