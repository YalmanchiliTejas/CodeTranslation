#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int n;
vector<int> q;
int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		int v=read();v=-v;
		int x=upper_bound(q.begin(),q.end(),v)-q.begin();
		if(x==q.size()) q.push_back(v);
		else q[x]=v;
	}printf("%d\n",q.size());
 	return 0;
}
