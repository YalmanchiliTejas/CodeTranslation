#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#define rep(i,l,r) for (int i=l;i<=r;i++)
#define down(i,l,r) for (int i=l;i>=r;i--)
#define clr(x,y) memset(x,y,sizeof(x))
#define maxn 200500
#define inf (int)1e9
#define ll long long
#define mm 1000000007
#define eps 1e-9
#define low(x) x&(-x)
#define pb push_back
#define mp make_pair
#define PII pair<int,int>
using namespace std;

ll read(){
    ll x=0,f=1; char ch=getchar();
    while (!isdigit(ch)) {if (ch=='-') f=-1; ch=getchar();}
    while (isdigit(ch)){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n=read();
	int op=0;
	deque<int> q;
	rep(i,1,n) {
		int x=read();
		if (!op) q.push_front(x);
		else q.push_back(x);
		op^=1; 
	}
	if (!op) {
		while (!q.empty()){
			int x=q.back(); q.pop_back();
			printf("%d ",x);
		}
	}
	else {
		while (!q.empty()) {
			int x=q.front(); q.pop_front();
			printf("%d ",x);
		}
	}
    return 0;
}