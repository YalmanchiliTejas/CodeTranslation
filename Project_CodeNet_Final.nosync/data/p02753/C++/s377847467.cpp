/**********************************************************
* @Author: 			   Maple
* @Date:   			   2020-03-07 20:02:37
* @Last Modified by:   Maple
* @Last Modified time: 2020-03-07 20:04:02
* @Remark: 
**********************************************************/
#include <bits/stdc++.h>
#define lowbit(x) (x&(-x))
#define CSE(x,y) memset(x,y,sizeof(x))
#define INF 0x3f3f3f3f
#define Abs(x) (x>=0?x:(-x))
#define FAST ios::sync_with_stdio(false);cin.tie(0);
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll , ll> pll;

const int maxn=1000;
char str[maxn];

int main()
{
	// #ifndef ONLINE_JUDGE
	// freopen("in.in","r",stdin);
	// #endif
	cin>>str;
	int a=0,b=0;
	for(int i=0;i<3;i++){
		if(str[i]=='A')
			a++;
		if(str[i]=='B')
			b++;
	}
	if(a>0&&b>0)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}