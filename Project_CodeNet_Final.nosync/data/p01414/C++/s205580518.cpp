#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
string s[4];
int x[16],y[16];
int d[1<<16];
int main(){
	int N;
	cin>>N;
	rep(i,N) cin>>x[i]>>y[i];
	rep(i,4) cin>>s[i];
	rep(i,1<<16) d[i]=1e9;
	d[0]=0;
	rep(i,1<<16){
		bool p[4][4]={};
		rep(j,4) rep(k,4) p[j][k]=(i>>(j*4+k))&1;
		rep(j,N){
			for(int a=-3;a<=3;a++) for(int b=-3;b<=3;b++){
				char c='W';
				bool can=1;
				int ni=i;
				rep(X,x[j]) rep(Y,y[j]){
					if(X+a<0||X+a>=4||Y+b<0||Y+b>=4) continue;
					if(!p[X+a][Y+b]){
						ni|=1<<((X+a)*4+Y+b);
						if(c=='W') c=s[X+a][Y+b];
						else if(c!=s[X+a][Y+b]){
							can=0;
							goto done;
						}
					}
				}
				done:
				if(can) chmin(d[ni],d[i]+1);
			}
		}
	}
	cout<<d[65535]<<endl;
}