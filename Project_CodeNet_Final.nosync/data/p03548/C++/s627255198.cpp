#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stack>
#include<map>
#include<vector>
#include<set>
using namespace std;
const int MAX=5e5+10;
const double eps=1e-4;
const int mod=1e9+7;
#define INF 0x7fffffff
#define ll long long
#define edl putchar('\n')
#define useit  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define mst(a) memset(a,0,sizeof(a))
#define mstn(a,n) memset(a,n,sizeof(a))
//struct point{int v,l;}a[MAX];
//double cross(point a,point b){return (a.x*b.y-a.y*b.x);}
//double dot(point a,point b){return (a.x*b.x+a.y*b.y);}

int main()
{
	int a,b,c;
	{
		cin>>a>>b>>c;
		a-=c;
		cout<<a/(b+c)<<endl;
	}
	
}