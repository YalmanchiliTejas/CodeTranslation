#include<bits/stdc++.h>
using namespace std;
string n;
int k;
int ans;
bool isok(string s1,string s2){
	if(s1.size()>s2.size())
		return true;
	if(s1.size()<s2.size())
		return false;
	for(int i=0;i<s1.size();i++){
		if(s1[i]>s2[i])
			return true;
		if(s1[i]<s2[i])
			return false;
	}
	return true;
}
bool isok2(string s1,string s2)
{
	int cnt=s1.size();
	for(int i=0;i<cnt;i++){
		if(i>=s2.size())
			return true;
		if(s1[i]>s2[i])
			return true;
		if(s1[i]<s2[i])
			return false;
	}
}
void dfs(string cnt,int l){
	if(!isok(n,cnt))
		return;
	if(l==0){
		ans++;
		int a=cnt.size();
		int b=n.size();
		if(b-a-1>=0){
			ans+=(b-a-1);
			if(isok2(n,cnt))
				ans++;
			return ;
		}
		else
			return ;
	}
	else{
		char a;
		for(int i=1;i<=9;i++){
			a=i+'0';
			dfs(cnt+a,l-1);
		}
		dfs(cnt+'0',l);
	}
}
int main()
{
	cin>>n>>k;
	string cnt="";
	for(int i=1;i<=9;i++){
		char a=i+'0';
		dfs(cnt+a,k-1);
	}
	cout<<ans<<endl;
	return 0;
}