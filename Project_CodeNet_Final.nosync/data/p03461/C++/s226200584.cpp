

#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
#define ll long long 
#define pb push_back
//#define mp make_pair
#define fr first
#define sc second
#define N ((ll)(2e6+100))
#define MAX ((ll)(1e16+100))
#define ARRS ((ll)(3e5+100))
#define MOD ((ll)(1e9+7))
#define M1 ((ll)(1001783))
#define M2 ((ll)(1001941))
#define M3 ((ll)(1002073))
#define pb push_back


ll w[200][200];
ll fi[200][200];
ll f[105][105][105];

struct va{
	ll a,b,c;
};
vector<va> v;
int main(){

	ll n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			cin>>w[i][j];

	for(int a=0; a<=100; a++){
		for(int b=0; b<=100; b++){
			for(int c=0; c<=100; c++){

				f[a][b][c]=1;
				for(int x=1; x<=n; x++)
					for(int y=1; y<=m; y++)
						if(w[x][y]>x*a+y*b+c)
							f[a][b][c]=0;

			}
		}
	}

	for(int a=0; a<=100; a++){
		for(int b=0; b<=100; b++){
			for(int c=0; c<=100; c++){

				for(int x=1; x<=n; x++)
					for(int y=1; y<=m; y++)
						if(f[a][b][c]&&w[x][y]==x*a+y*b+c)
							fi[x][y]=1;

			}
		}
	}


	bool e=1;
	for(int x=1; x<=n; x++)
		for(int y=1; y<=m; y++)
			e&=fi[x][y];


	if(e){
		for(int i=1; i<=100; i++)
			v.pb({i,i+1,-1});
		for(int j=1; j<=100; j++)
			v.pb({j+101,101+j+1,-2});

		for(int a=0; a<=100; a++)
			for(int b=0; b<=100; b++)
				for(int c=0; c<=100; c++)
					if(f[a][b][c])
						{v.pb({a+1,202-b,c});break;}

		cout<<"Possible\n";
		cout<<202<<" "<<v.size()<<endl;
		for(auto x:v)
			if(x.c==-1)
				cout<<x.a<<" "<<x.b<<" "<<"X"<<endl;
			else if(x.c==-2)
				cout<<x.a<<" "<<x.b<<" "<<"Y"<<endl;
			else
				cout<<x.a<<" "<<x.b<<" "<<x.c<<endl;
		cout<<1<<" "<<202;
	}
	else {
		cout<<"Impossible";
	}
}
 
