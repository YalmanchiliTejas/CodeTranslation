#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<algorithm>
#include<queue>
#include<list>
#include<stack>
#include<cstdio>
#include<fstream>
#include<numeric>
#include<functional>
#include<utility>
#include<memory>
#include <cstring>
#include<bits/stdc++.h>
using namespace std; 
  
#define CLEAN(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;

int main() 
{
	int r,g,b;
	cin>>r>>g>>b;
	if ((100*r+10*g+b)%4==0) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}