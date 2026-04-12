#include <iostream>
#include <algorithm>
using namespace std;
string s;
int k,ans;
inline void dfs(int pos,int x,int flag)
{
	if(pos==s.size())
	{
		if(!x) ++ans;
		return ;
	}
	if(!x)
	{
		++ans;
		return ;
	}
	for(int i='1';i<='9';i++)
	{
		if(i>s[pos]&&flag) break;
		if(i>=s[pos]) dfs(pos+1,x-1,flag);
		if(i<s[pos]) dfs(pos+1,x-1,0);
	}
	dfs(pos+1,x,flag&(s[pos]=='0'));
}
int main(int argc, char** argv) {
	cin >> s >> k;
	dfs(0,k,1);
	cout << ans;
	return 0;
}