#include "bits/stdc++.h"

using namespace std;
using ll=long long;
using ull=unsigned long long;

typedef pair<int,int>Pi;
typedef pair<long long,long long>P;
typedef pair<long long,P>PP;
typedef pair<P,P>PPP;

const long long MOD=1e9+7;
const long long INF=5e18;
const int di[4]={1,0,-1,0};
const int dj[4]={0,1,0,-1};

#define fr first
#define sc second
#define pb push_back
#define eb emplace_back
#define ALL(x) (x).begin(),(x).end()
#define ALLR(x) (x).rbegin(),(x).rend()

int h,w,ni,nj;
string s[10];
bool b[10][10];

bool check(int i,int j){
	if(i>=0&&i<h&&j>=0&&j<w)return true;
	return false;
}

void input(){
	cin>>h>>w;
	for(int i=0;i<h;i++)cin>>s[i];
	return;
}

void solve(){
	int i=0,j=0;
	b[0][0]=true;
	while(i<h&&j<w){
		if(i+1<h&&s[i+1][j]=='#'){
			b[i+1][j]=true;
			i++;
		}
		else if(j+1<w&&s[i][j+1]=='#'){
			b[i][j+1]=true;
			j++;
		}
		else break;
	}
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(s[i][j]=='#'&&!b[i][j]){
				cout<<"Impossible"<<endl;
				return;
			}
		}
	}
	cout<<"Possible"<<endl;
	return;
}

int main(){
	input();
	solve();
	return 0;
}