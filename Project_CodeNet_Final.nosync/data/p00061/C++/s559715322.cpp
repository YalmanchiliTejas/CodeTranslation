#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef pair<int,int> pp;

bool cmp( pp a , pp b){
	return a.second > b.second;
}

int main(){
	int a,b,n;
	vector<pp> hello;
	while(scanf("%d,%d",&a,&b) && a){
			hello.push_back(make_pair(a,b));
	}
	vector<int> rank(hello.size());
	sort(hello.begin(),hello.end(),cmp);
	int r = 0;
	int mi = (1<<21);
	for(int i=0;i<hello.size();i++){
		if(mi > hello[i].second){
			r++;
			mi = hello[i].second;
		}
		rank[hello[i].first-1] = r ;
				
	}
	
	while(cin >> n){
		cout << rank[n-1] << endl;
	}
}