#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
#include<ctime>
#include<cstring>
#include<stack>
#include<queue>
#include<sstream>
#include<string>
#include<set>
#include<array>

#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i);

using namespace std;

string r="qwertasdfgzxcvb";
string l="yuiophjklnm";

bool serch(string str,char ch){
	rep(i,str.size()){
		if(str[i]==ch) return true;
	}
	return false;
}

int main(){
	while(1){
		string str;
		cin >>str;
		if(str=="#")break;
		int flag=-1;//1??????,0??????
		int ans=0;
		if(serch(r,str[0])) flag=1;
		else flag=0;

		for(int i=1;i<str.size();i++){
			if(serch(r,str[i])&&flag==0){
				ans++;
				flag=1;
			}else if(serch(l,str[i])&&flag==1){
				ans++;
				flag=0;
			}	
		}
		cout << ans << endl;
	}

	return 0;
}