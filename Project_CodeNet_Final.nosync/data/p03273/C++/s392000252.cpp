#include <iostream>
using namespace std;
#define FOR(i,a,b) for (int i=(a); i<=(b); ++i)
#define int long long

char f[101][101];
bool okw[101],okh[101];

signed main(){
    int h,w;cin>>h>>w;
	FOR(i,0,h-1)FOR(j,0,w-1)cin>>f[i][j];
	FOR(i,0,h-1)okh[i]=false;
	FOR(j,0,w-1)okw[j]=false;
	FOR(i,0,h-1)
	{
		bool ok = true;
		FOR(j,0,w-1)if(f[i][j] == '#')ok=false;
		if(ok)okh[i]=true;
	}

	FOR(j,0,w-1)
	{
		bool ok = true;
		FOR(i,0,h-1)if(f[i][j] == '#')ok=false;
		if(ok)okw[j]=true;
	}
	
	FOR(i,0,h-1)
	{
		if(okh[i])continue;
		FOR(j,0,w-1)
		{
			if(okw[j])continue;
			cout << f[i][j];
		}
		cout << endl;
	}
   
}