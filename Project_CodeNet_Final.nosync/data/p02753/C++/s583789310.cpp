#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool vis[1000][1000];
int n,m;
int main() {
	
string st;
set<char>s;
cin>>st;
for(int i=0;i<3;i++)
s.insert(st[i]);
cout<<(s.size()==2?"Yes":"No");

}