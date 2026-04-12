#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<iostream>
#include<sstream>
#include<utility>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<stack>
#include <functional>
#include<algorithm>
#include <iterator>

using namespace std;
typedef long long ll;
typedef pair<int,int>P;
const int INF=1e9;

int main()
{
	int N,res=1;
	cin>>N;
	vector<int>A,B(N+1,INF);
	for(int i=0;i<N;i++)
	{
		int a;
		cin>>a;
		A.push_back(-a);
	}
	for(int i=0;i<N;i++)
	{
		*lower_bound(B.begin(),B.end(),A[i]+1)=A[i];
	}

	cout<<(lower_bound(B.begin(),B.end(),INF)-B.begin())<<endl;
}