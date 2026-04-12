#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	cout<<(n==m?"Yes":"No")<<endl;
	return 0;
}
