/**/
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cctype>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#define mm(i,v) memset(i,v,sizeof i);
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll INF=99999999999999;
const int inf=999999999;

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,k;
	char s[100];
	cin>>n>>s>>k;
	char t=s[k-1];
	for(int i=0;i<n;i++)
		if(s[i]!=t)
			s[i]='*';
	cout<<s;
	return 0;
}

/*
    summary:
*/
