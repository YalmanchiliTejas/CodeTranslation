#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#define mp make_pair
using namespace std;

typedef pair<int,string> P;
typedef pair<int,P> PP;

int main(){
	int n;
	bool flag = false;
	while(cin >> n,n){
		if(flag) cout << endl;
		else flag = true;
		vector<PP> vec;
		for(int i = 0;i < n;i++){
			string s;
			int a,b,c;
			cin >> s >> a >> b >> c;
			vec.push_back(mp(a * 3 + c,mp(-i,s)));
		}
		sort(vec.begin(),vec.end(),greater<PP>());
		for(int i = 0;i < n;i++){
			cout << vec[i].second.second;
			printf(",%d\n",vec[i].first);
		}
	}
	return 0;
}