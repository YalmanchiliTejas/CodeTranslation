//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=10001
//Tuvshee

#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<cctype>
#include<vector>
#include<queue>
using namespace std;
#define I int
#define D double
#define F float
#define C char
#define S string
#define B bool
#define L long long
#define rep(n) for(int i=0;i<n;i++)
#define reps(m,n,c) for(int c=m;c<n;c++)
#define repd(m,n,j) for(int j=n;j>m;j--)
#define whL while
#define eL endl
#define oR ||
#define rtn return
#define pause system("PAUSE")
#define Max 300
#define max(m,n) ((n<m)?m:n)
#define min(m,n) ((n>m)?m:n)

I main()
{
	I a, b;
	cin>>a>>b;
	if(a<b)cout<<"a < b"<<eL;
	else if(a>b)cout<<"a > b"<<eL;
	else cout<<"a == b"<<eL;
	rtn 0;
}