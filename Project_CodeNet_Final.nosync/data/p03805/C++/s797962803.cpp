


#include <iostream>
#include <utility>
#include <vector>
#include <stack>
using namespace std;

int numpath(int cur, vector<int> visited, vector<pair<int, int> > p){
	visited[cur]=1;
	int r=0;
	int f=0;
	for(int &n: visited){
		if(n==0) f=1;
	}
	if(f==0) return 1;
	else{
		for(pair<int, int> &n: p){
			if(n.first==cur && visited[n.second]==0){
				r+=numpath(n.second, visited, p);
			}
		}
		return r;
	}
}

int main(){
	int n, m;
	cin >> n >> m;

	vector<pair<int, int> > p(2*m);

	for(int i=0; i<m; i++){
		int j, k;
		cin >> j >> k;
		p[i]=make_pair(j, k);
		p[m+i]=make_pair(k, j);
	}

	int r;
	vector<int> visited(n+1,0);
	visited[0]=1;

	r=numpath(1,visited,p);

	cout << r << endl;

	return 0;

}


