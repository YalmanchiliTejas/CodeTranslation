#include <bits/stdc++.h>
#define F first
#define S second
#define all(a) a.begin(),a.end()
#define setDP(arr) memset(arr,-1,sizeof arr)
#define Clear(arr) memset(arr,0,sizeof arr)
#define li(x) x.size()-1
#define oo 2000000000
#define inf 1000000000000000000
#define M 1000000007
typedef unsigned long long ll;
using namespace std;
const int N =3e5+10;
const int SQRTN = 320;
const int LOGN = 20;
const double PI = acos(-1);
const double Tau = 2*acos(-1);

int n , m;
char g[111][111];
char p[111][111];

int main() {
	cin >> n >> m ;
	for(int i = 0 ; i < n ; i++){
		scanf(" %s",g[i]);
		int ctr = 0;
		for(int j = 0; j < m ; j++){
			ctr+=(g[i][j]=='#');
		}
		if(ctr==0){
			for(int j = 0; j < m ; j++)p[i][j]=1;
		}
	}
	
	for(int i = 0 ; i < m ; i++){
		int ctr = 0;
		for(int j = 0; j < n ; j++){
			ctr+=(g[j][i]=='#');
		}
		if(ctr==0){
			for(int j = 0; j < n ; j++)p[j][i]=1;
		}
	}
	vector<vector<char> > v;
	vector<char> v2;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(!p[i][j])v2.push_back(g[i][j]);
		}
		if(v2.size()){
			v.push_back(v2);
			v2.clear();
		}
	}
	for(int i = 0 ; i < v.size() ; i++){
		for(int j = 0 ; j < v[i].size() ; j++){
			cout << v[i][j];
		}
		cout << endl;
	}
    return 0;
}
