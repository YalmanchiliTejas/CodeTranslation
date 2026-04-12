#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

#define ll long long
#define pb push_back

int main(){

	int H,W,cnt=0;
	vector<string> S;
	bool flag;

	cin>>H>>W;
	string tmp;
	for(int i=0;i<W;i++){
		tmp.pb('.');
	}
	for(int i=0;i<H;i++){
		string s;
		cin>>s;
		if(s!=tmp){
			S.pb(s);
			cnt++;
		}
	}
	for(int i=0;i<W;i++){
		flag=true;
		for(int j=0;j<cnt;j++){
			if(S[j][i]=='#')flag=false;
		}
		if(flag){
			for(int j=0;j<cnt;j++){
				S[j][i]='a';
			}
		}
	}
	for(int i=0;i<cnt;i++){
		for(int j=0;j<W;j++){
			if(S[i][j]!='a')cout<<S[i][j];
		}
		cout<<endl;
	}

	return 0;
}