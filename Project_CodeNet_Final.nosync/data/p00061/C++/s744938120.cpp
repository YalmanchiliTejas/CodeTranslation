#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
typedef pair<int,int> P;
int main(){
	P p,tp;
	vector<P> v,rank;
	char c;
	int a,b,r = 1;
	while(cin >> a >> c >> b,a){
		p.first = b;
		p.second = a;
		v.push_back(p);
	}
	sort(v.begin(),v.end(),greater<P>());
	for(int i = 0;i < v.size();++i){
		tp.first = v[i].second;
		if(r == 1){
			tp.second = r;
			rank.push_back(tp);
			++r;
		}
		else {
			if(v[i - 1].first == v[i].first){
				tp.second = r - 1;
				rank.push_back(tp);
			}
			else {
				tp.second = r;
				rank.push_back(tp);
				++r;
			}
		}
	}
	while(cin >> a){
		for(int i = 0;i < rank.size();++i){
			if(rank[i].first == a) cout << rank[i].second << endl;
		}
	}
	return 0;
}