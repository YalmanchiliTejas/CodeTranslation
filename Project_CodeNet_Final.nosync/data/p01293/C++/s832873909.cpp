#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <cstring>
#include <functional>
#include <cmath>
#include <complex>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define rep1(i,n) for(int i=1;i<=(n);++i)
#define all(c) (c).begin(),(c).end()
#define fs first
#define sc second
#define pb push_back
#define show(x) cout << #x << " " << x << endl
int a(char c){
	if(isdigit(c)) return c-'0';
	if(c=='T') return 10;
	if(c=='J') return 11;
	if(c=='Q') return 12;
	if(c=='K') return 13;
	if(c=='A') return 14;
}
int main(){
	while(true){
		char c;
		cin>>c;
		if(c=='#') break;
		string s[4][13];
		rep(i,4) rep(j,13) cin>>s[i][j];
		int ew=0,ns=0;
		int l=0;
		rep(i,13){
			bool t=false;
			rep(j,4){
				if(!t&&s[j][i][1]==c){
					t=true;
					l=j;
				}else if(!t&&s[j][i][1]==s[l][i][1]&&a(s[j][i][0])>a(s[l][i][0])){
					l=j;
				}else if(t&&s[j][i][1]==c&&a(s[j][i][0])>a(s[l][i][0])){
					l=j;
				}
			}
			if(l%2) ew++;
			else ns++;
		}
		if(ew>ns) cout<<"EW "<<ew-6<<endl;
		else cout<<"NS "<<ns-6<<endl;
	}
}