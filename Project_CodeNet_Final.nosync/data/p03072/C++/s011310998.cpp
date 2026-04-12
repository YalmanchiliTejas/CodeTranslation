#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#define mm(i,v) memset(i,v,sizeof i);
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int maxn=25;
int a[maxn];
int n;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=2;i<=n;i++){
		if(a[i]>=a[1]){
			int f=0;
			for(int j=2;j<=i;j++){
				if(a[j]>a[i]){
					f=1;
					break;
				}
			}
			if(f==0)
				cnt++;
		}
	}
	cout<<cnt+1<<"\n";
	return 0;
}
