#include <bits/stdc++.h>
using namespace std;

int check(int n, int path[8][8],int now) {
  	bool fin = true;
	int count = 0;
	path[now][now] = 9;
	for(int i = 1; i < n; i++) {
		if(path[i][i] != 0) {
			continue;
		}
		if(path[i][now] == 1) {
			count += check(n,path,i);
          	fin = false;
        }
	}
  
  	path[now][now] = 0;
	
  	if(fin) {
		for(int i = 0; i < n; i++) {
        	if(i == now)
              	continue;
          	if(path[i][i] == 0)
              	return 0;
        }
      	return 1;
    } else { 
        return count;
    }
}
int main()
{
	int n,m,count = 0;
	cin >> n >> m;
	vector<int> a(m);
	vector<int> b(m);
	int path[8][8];
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j <= 8; j++) {
			path[i][j] = 0;
		}
	}
	
	for(int i = 0; i < m; i++) {
		cin >> a[i] >> b[i];
		path[--a[i]][--b[i]] = 1;
		path[b[i]][a[i]] = 1;
	}
	count = check(n,path,0);
	
	
	cout << count << endl;
}
