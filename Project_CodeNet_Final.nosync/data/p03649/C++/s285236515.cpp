#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
ll a[60];
int main() {
    int n;
    ll sum=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    while(1) {
	int x=0;
	for(int i=1;i<=n;i++)
	    if(a[i]>a[x]) x=i;
	if(a[x]<n) break;
	ll s=a[x]/n;sum+=s;
	for(int i=1;i<=n;i++)
	    if(i^x) a[i]+=s;
	a[x]-=s*n;
    }
    cout<<sum;
    return 0;
}