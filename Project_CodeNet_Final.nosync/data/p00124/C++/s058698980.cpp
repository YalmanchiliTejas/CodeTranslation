#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <stack>
#include <list>
using namespace std;
#define INF 100000000
typedef long long int lli;
typedef pair<int,int> P;


int main(){
	int n;
	bool f=false;
	while(cin >> n&&n){
		if(f) cout << "\n";
		f=true;
		vector<string> name;
		vector<int> point;
		
		for(int i=0; i<n; ++i){
			int win,lose,draw;
			string s;
			cin >> s >> win >> lose >> draw;
			name.push_back(s);
			point.push_back(win*3+draw);
		}
		
		for(int i=1; i<n; ++i){
			string s_tmp=name[i];
			int i_tmp=point[i];
			int j;
			for(j=i; ; --j){
				if(j==0||point[j-1]>=i_tmp) break;
				point[j]=point[j-1];
				name[j]=name[j-1];
			}
			point[j]=i_tmp;
			name[j]=s_tmp;
		}
		
		for(int i=0; i<n; ++i){
			cout << name[i] << "," << point[i] << "\n";
		}
	}
}