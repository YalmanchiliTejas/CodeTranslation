#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
using namespace std;
#define mp make_pair
#define pb push_back
#define re return
#define fi first
#define se second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<vi> vvi;
long long ans;
long long num[55],len[55];
long long  min(long long a,long long b){
	if(a>b)return b;
	return a;
}
long long dfs(long long n,long long x){
	if(n==0 && x==1)return 1;
	if(n>=0 && x==1)return 0;
	if(x==len[n])return num[n];
	long long aans=0;
	x--;
	aans+=dfs(n-1,min(x,len[n-1]));
	x=x-len[n-1];
	if(x<=0)return aans;
	x--;
	aans++;
	if(x<=0)return aans;
	aans+=dfs(n-1,min(len[n-1],x));
	return aans;
}
int main() {
    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	num[0]=1;
	len[0]=1;
	for(int i=1;i<=50;i++){
		num[i]=num[i-1]*2+1;
		len[i]=len[i-1]*2+3;
	}
	long long n,x;
	cin>>n>>x;
	ans=dfs(n,x);
	cout<<ans<<endl;
    return 0;
}