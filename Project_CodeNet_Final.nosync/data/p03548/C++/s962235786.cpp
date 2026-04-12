#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const int maxn=0x7fffff;
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	n-=k;
	cout<<n/(m+k);
	return 0;
}
