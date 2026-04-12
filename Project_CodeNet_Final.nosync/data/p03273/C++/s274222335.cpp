#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define ll long long 
const int N = 1005;

char a[N][N];
int n,b[N][N],m;

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			int k,l;
			k = l = j;
			while(a[i][k] == '.') k--;
			while(a[i][l] == '.') l++;
			if(k == 0 && l > m) 
				for(int p = 1; p <= m; p++)
					b[i][p] = 1;
			k=l=i;
			while(a[k][j] == '.') k--;
			while(a[l][j] == '.') l++;
			if(l > n && k == 0)
				for(int p = 1; p <= n; p++)
					b[p][j] = 1;
		}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++)
			if(b[i][j]) continue;
			else cout << a[i][j];
		int tot = 0;
		for(int j = 1; j <= m; j++) if(b[i][j] == 0) tot = 1;
		if(!tot) continue;
		else cout << endl;
	}
} 