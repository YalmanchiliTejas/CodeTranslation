#include<iostream>
#include<vector>
#include<algorithm>
#include <string>
#include<cmath>
#include<map>
#include<cstdio>
#include<stack>
#include<queue>

#define ok cout<<"ok"<<endl
#define MAX 1000000
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=(s);i<(n);i++)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define REPR(i,s,n) for(int i=(s);i>=(g);(i)--)
#define all(a) (a).begin(),(a).end()
#define pb push_back
using namespace std;
	
int main()
{
	int x,y,z;
	cin >> x >> y >> z;
	int ans= (x-z)/(y+z);
	cout << ans;
	
	return 0;
}