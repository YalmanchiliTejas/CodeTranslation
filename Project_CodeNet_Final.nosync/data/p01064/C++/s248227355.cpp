#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include<cstring>
#include<cstdio>
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
int main(){
	int n;
	cin>>n;
	int a,d;
	cin>>a>>d;
	int m;
	cin>>m;
	vvi in(m,vi(3));
	rep(i,m)rep(j,3)cin>>in[i][j];
	int q;
	cin>>q;
	
	for(int i=m-1;i>=0;i--)if(in[i][0]==0&&in[i][1]<=q&&q<=in[i][2]){
		q=in[i][2]-q+in[i][1];
	}
	int out=a+d*(q-1);
	rep(i,m){
		if(in[i][0]==1){if(in[i][1]<=q&&q<=in[i][2])out++;}
		else if(in[i][0]==2){if(in[i][1]<=q&&q<=in[i][2])out/=2;}
		else if(in[i][1]<=q&&q<=in[i][2]){
			q=in[i][2]-q+in[i][1];
		}
	}
	cout<<out<<endl;
	
}