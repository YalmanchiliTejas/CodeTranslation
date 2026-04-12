#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a)  (a).begin(),(a).end()
#define pb push_back
#define INF (1e9+1)
//#define INF (1LL<<59)

char trump;

int to(char ch){
	if(isdigit(ch)){
		return ch-'0';
	}
	else if(ch=='T')return 10;
	else if(ch=='J')return 11;
	else if(ch=='Q')return 12;
	else if(ch=='K')return 13;
	else if(ch=='A')return 14;
	else {
		assert(1);
		return 0;
	}
}

bool bigger(string a,string b){
	if(b=="*")return true;
	if(a[1]==trump&&b[1]!=trump)return true;
	else if(a[1]!=trump&&b[1]==trump)return false;
	else{
		int x,y;
		x = to(a[0]);
		y = to(b[0]);
		return x>y;
	}
}

int solve(vector<string> v,int led){
	char ls = v[led][1];
	string maxi = "*";
	int pos = -1;
	rep(i,4){
		if(v[i][1]!=trump&&v[i][1]!=ls)continue;
		if(bigger(v[i],maxi)){
			maxi = v[i];
			pos = i;
		}
	}
	return pos;
}

int main(){
	while(cin>>trump&&trump!='#'){
		int led = 0;
		string str[4][13];
		rep(i,4)rep(j,13)cin>>str[i][j];
		
		int ns=0,ew=0;
		rep(i,13){
			vector<string> v;
			rep(j,4)v.pb(str[j][i]);
			int win = solve(v,led);
			if(win%2==0)ns++;
			else ew++;
			led = win;
		}
		
		if(ns>ew)cout<<"NS "<<ns-6<<endl;
		else cout<<"EW "<<ew-6<<endl;
	}
}