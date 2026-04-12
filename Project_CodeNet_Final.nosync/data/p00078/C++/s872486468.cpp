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
#define rp(a) while(a--)
#define pb push_back
#define mp make_pair
#define all(in) in.begin(),in.end()
const double PI=acos(-1);
const double EPS=1e-10;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int main(){
	int n;
	while(cin>>n,n){
		int in[15][15]={0};
		int x=n/2+1;
		int y=n/2;
		in[x][y]=1;
		loop(i,2,n*n+1){
			x++;y++;
			if(y==n)y=0;
			if(x==n)x=0;
			if(y==-1)y=n-1;
			if(in[x][y]!=0){
				i--;y-=2;
			}else in[x][y]=i;
		}
		rep(i,n){
			rep(j,n)printf("%4d",in[i][j]);
			puts("");
		}
	}
}