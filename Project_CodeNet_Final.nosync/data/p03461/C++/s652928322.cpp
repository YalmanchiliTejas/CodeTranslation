#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <array>
#include <bitset> 
#include <unordered_map>

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

int d[11][11];
int dist[101][101];
int done[11][11];
int main() {
	int A,B;
	cin >> A >> B;
	for(int i=1;i<=A;i++){
		for(int j=1;j<=B;j++){
			cin >> d[i][j];
		}
	}
	for(int i=0;i<101;i++){
		for(int j=0;j<101;j++){
			int m=0;
			for(int x=1;x<=A;x++){
				for(int y=1;y<=B;y++){
					m=max(m,d[x][y]-x*i-y*j);
				}
			}
			for(int x=1;x<=A;x++){
				for(int y=1;y<=B;y++){
					if(m==d[x][y]-x*i-y*j){
						done[x][y]=true;
					}
				}
			}
			dist[i][j]=m;
			if (i<5&&j<5){
				cerr << i << ", " << j << ": " << dist[i][j] << endl;
			}
		}
	}
	for(int x=1;x<=A;x++){
		for(int y=1;y<=B;y++){
			if(!done[x][y]){
				cout << "Impossible" << endl;
				return 0;
			}
		}
	}
	cout << "Possible" << endl;
	cout << 202 << " " << 2*100+101*101 << endl;
	for(int i=0;i<100;i++){
		cout << i+1 << " " << i+2 << " X" << endl;
	}
	for(int i=0;i<100;i++){
		cout << i+103 << " " << i+102 << " Y" << endl;
	}
	for(int i=0;i<101;i++){
		for(int j=0;j<101;j++){
			cout << i+1 << " " << j+102 << " " << dist[i][j] << endl;
		}
	}
	cout << 1 << " " << 102 << endl;


	return 0;
}

