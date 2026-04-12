#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <queue>
#include <vector>
#include <sstream>
#include <functional>
using namespace std;
typedef pair<int,string> p;
p team[10];
int main()
{
	int n;
	bool first=true;
	while(cin>>n&&n){
		if(!first)cout<<endl;
		for(int i=0;i<n;i++){
			int k,m,h;
			cin>>team[i].second>>k>>m>>h;
			team[i].first=(k*3+h)*100+10-i;
		}
		sort(team,team+n,greater<p>());
		for(int i=0;i<n;i++){
			cout<<team[i].second<<","<<(int)team[i].first/100<<endl;
		}
		first=false;
	}
    return 0;
}