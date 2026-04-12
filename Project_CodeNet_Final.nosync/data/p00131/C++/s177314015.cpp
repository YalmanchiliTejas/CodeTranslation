#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<vector>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<time.h>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define all(in) in.begin(),in.end()
const double PI=acos(-1);
const double EPS=1e-10;
const int inf=1e8;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
vvi out(10,vi(10)),in(10,vi(10)),tmp(10,vi(10));
vi top(10);
int dx[]={-1,0,0,0,1};
int dy[]={0,-1,0,1,0};
bool solve2(){
	rep(i,10)rep(j,10)out[i][j]=0;
	tmp=in;
	rep(i,10)if(top[i]){
		out[0][i]=1;
		rep(j,5){
			int nx=dx[j];
			int ny=i+dy[j];
			if(nx>=0&&nx<10&&ny>=0&&ny<10)tmp[nx][ny]=!tmp[nx][ny];
		}
	}
	loop(i,1,10)rep(j,10)if(tmp[i-1][j]){
		out[i][j]=1;
		rep(k,5){
			int nx=i+dx[k];
			int ny=j+dy[k];
			if(nx>=0&&nx<10&&ny>=0&&ny<10)tmp[nx][ny]=!tmp[nx][ny];
		}
	}
	bool h=true;
	rep(i,10)rep(j,10)if(tmp[i][j])h=false;
	return h;
}
bool solve(int a){
	if(a==10)if(solve2())return true;
	else return false;
	
	top[a]=1;
	if(solve(a+1))return true;
	top[a]=0;
	if(solve(a+1))return true;
	return false;
}
int main(){
	int n;
	cin>>n;
	while(n--){
		rep(i,10)top[i]=0;
		rep(i,10)rep(j,10)cin>>in[i][j];
		solve(0);
		rep(i,10){
			rep(j,9)cout<<out[i][j]<<" ";
			cout<<out[i][9]<<endl;
		}
	}
}