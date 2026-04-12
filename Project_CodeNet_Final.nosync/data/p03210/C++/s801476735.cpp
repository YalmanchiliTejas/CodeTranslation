#include <bits//stdc++.h>
using namespace std;
int in(void){int x;cin>>x;return x;}
#define ll long long int;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main() {
	int x=in();
	if(x==7||x==5||x==3)cout<<"YES";
	else cout<<"NO";
	return 0;
}
