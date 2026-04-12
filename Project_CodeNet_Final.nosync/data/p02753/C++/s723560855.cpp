#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<stack>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
#define INF 0x3f3f3f3f
#define mod 1000000009
#define e  2.718281828459045
#define eps 1.0e18
#define PI acos(-1)
#define lowbit(x) (x&(-x))
#define memset(x,y) memset(x,y,sizeof(x))
#define lson i << 1,l,m
#define rson i << 1 | 1,m + 1,r
#define ll long long
using namespace std;
priority_queue <int> q;
const int N = 3e5+5;
int a[N];
int main(){
	ios::sync_with_stdio(false);
	string s;
	cin>>s;
	if(s=="AAA"||s=="BBB") cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
	return 0;
}
