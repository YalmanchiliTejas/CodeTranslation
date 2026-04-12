#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int h,w; cin>>h>>w;
	vector<vector<string>> vv(h,vector<string>(w));
	
	vector<int> vh;
	rep(i,h){
		string s; cin>>s;
		bool flg=false;
		rep(j,w){
			if(s[j]=='.') flg=true;
			else {flg=false; break;}
		}
		rep(j,w) vv[i][j]=s[j];
		if(flg) continue;
		else vh.push_back(i);
	}

	vector<int> vw;
	rep(i,w){
		bool flg=false;
		rep(j,h){
			if(vv[j][i]==".") flg=true;
			else {flg=false; break;}
		}
		if(!flg) vw.push_back(i);
	}

	h=vh.size();
	w=vw.size();
	rep(i,h){
		rep(j,w) cout<<vv[vh[i]][vw[j]];
		cout<<endl;
	}
}