#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n,m,t;
	int mi;
	vector<int> p;
	
	while(cin >> n >> m && n || m){
		mi = 0;
		p.clear();
		for(int i=0;i<n+m;i++){
			cin >> t;
			p.push_back(t);
		}
		p.push_back(0);
		sort(p.begin(),p.end());
		for(int i=0;i+1<n+m+1;i++){
			mi = max(mi,p[i+1]-p[i]);
		}
		cout << mi << endl;
	}
}