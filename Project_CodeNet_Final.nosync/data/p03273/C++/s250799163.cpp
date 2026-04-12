#include<bitset>
#include<math.h>
#include<limits.h>
#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<sstream>
#include<list>
#include<queue>
#include<algorithm>
#include<functional>
#include<map>
#include<set>
#include<utility>
#include<initializer_list>
#include<tuple>
#include<regex>
using namespace std;
#define ull unsigned long long
#define ll long long
#define rep(i, a, n) for(int i=(a);i<(int)(n);i++)
#define repc(i, a, n) for(int i=(a);i<=(int)(n);i++)
#define all(t) t.begin(), t.end()
#define rall(t) t.rbegin(), t.rend()
#define mat(type, row, col, init) vector<vector<type>>(row, vector<type>(col, init));
#define Yes(cond) cout<<(cond? "Yes":"No")<<endl;
#define YES(cond) cout<<(cond? "YES":"NO")<<endl;
#define DBG(str) cerr<<(str)<<endl;
int main() {
	int h,w;
	cin>>h>>w;
	auto a =mat(char,h+1,w+1,0);
	rep(i,1,h+1){
		rep(j,1,w+1){
			cin>>a[i][j];
		}
	}
	bool all=0;
	rep(i,1,h+1){
		all=true;
		rep(j,1,w+1){
			if(a[i][j]!='.'){
				all=false;
			}
		}
		if(all)a[i][0]=1;
	}
	rep(i,1,w+1){
		all=true;
		rep(j,1,h+1){
			if(a[j][i]!='.'){
				all=false;
			}
		}
		if(all)a[0][i]=1;
	}
	rep(i,1,h+1){
		if(a[i][0]!=1){
			rep(j,1,w+1){
				if(a[0][j]==0) cout<<a[i][j];
			}
			cout<<endl;
		}
	}
	
	return 0;
}



