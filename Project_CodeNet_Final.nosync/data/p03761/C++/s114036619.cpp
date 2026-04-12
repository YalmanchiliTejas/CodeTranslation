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
#include<algorithm>
#include<set>
#include<stack>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
int N,s[50]={0};
string S;
int main()
{
	scanf("%d\n",&N);
	cin>>S;
	for(int i=0;i<S.length();i++)s[S[i]-'a']++;
	for(int i=1;i<N;i++)
	{
		int t[50]={0};
		cin>>S;
		for(int i=0;i<S.length();i++)t[S[i]-'a']++;
		for(int i=0;i<30;i++)s[i]=min(s[i],t[i]);
	}
	for(int i=0;i<30;i++)
		for(int j=0;j<s[i];j++)
			putchar('a'+i);
	puts("");
	return 0;
}
