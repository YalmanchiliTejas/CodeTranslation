#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
 
#define rep(i, n) for (int i = 0; i < n; i++)
#define repd(i, n) for (int i = n; i > 0; i--)
 
using namespace std;
typedef long long int ll;
typedef pair <int, int> P;
 
int main(){
	int h,w;
	cin>>h>>w;
	vector<string> a;
	rep(i,h){
		string s;
		cin>>s;
		bool flg=false;
		rep(j,w){
			if(s[j]!=*"."){
				flg=true;
			}
		}
		if(flg){
			a.push_back(s);
		}
	}
	vector<string> b(a.size());
	rep(i,w){
		bool flg=false;
		rep(j,a.size()){
			if(a[j][i]!=*"."){
				flg=true;
			}
		}
		if(flg){
			rep(j,a.size()){
				b[j]+=a[j][i];
			}
		}
	}
	rep(i,b.size()){
		cout<<b[i]<<endl;
	}
	return 0;
}