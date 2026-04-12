#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = 1000000007;
#define op(x) (x&(-x))
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define si(n) scanf("%d",&n)
#define s2i(x,y) scanf("%d %d",&x,&y);
#define s3i(x,y,z) scanf("%d %d %d",&x,&y,&z);
#define s4i(x,y,z,w) scanf("%d %d %d %d",&x,&y,&z,&w);
#define print(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl;
#define print2d(a,n,m) for(int i=0;i<n;i++) {for(int j=0;j<m;j++) cout<<a[i][j]<<" "; cout<<endl;}

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);

char a[10][10];
int h,w;

int main()
{
	cin>>h>>w;
	for(int i=0;i<h;i++) cin>>a[i];
	if(a[0][0]!='#') {cout<<"Impossible"<<endl; return 0;}
	if(a[h-1][w-1]!='#') {cout<<"Impossible"<<endl; return 0; }
	a[0][0]='X';
	int i = 0, j = 0;
	while(1)
	{
		if(i==h-1&&j==w-1) {a[i][j]='X'; break;}
		if(i+1<=h-1&&j+1<=w-1)
		{
			if(a[i+1][j]=='#'&&a[i][j+1]=='#') {cout<<"Impossible"<<endl; return 0;}
			else if(a[i+1][j]=='#') a[i+1][j]='X', i++;
			else if(a[i][j+1]=='#') a[i][j+1]='X', j++;
			else {cout<<"Impossible"<<endl; return 0;}
		}
		else if(i+1<=h-1)
		{
			if(a[i+1][j]=='#') a[i+1][j]='X', i++;
			else {cout<<"Impossible"<<endl; return 0;}
		}
		else 
		{
			if(a[i][j+1]=='#') a[i][j+1]='X', j++;
			else {cout<<"Impossible"<<endl; return 0;}
		}
	}
	bool flag = false;
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(a[i][j]=='#')
			{
				flag = true;
				break;
			}
		}
	}
	if(flag)
		cout<<"Impossible"<<endl;
	else
		cout<<"Possible"<<endl;
	return 0;
}