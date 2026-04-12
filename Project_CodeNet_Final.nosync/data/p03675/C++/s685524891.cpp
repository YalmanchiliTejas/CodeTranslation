#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <string>
#include <stack>
#include <set>
#include <deque>
#define mp make_pair
using namespace std;
int n,a[200005],b[500005];
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	int s=250005,e=250004;
	for (int i=0;i<n;i++){
		if (i%2==0){
			e++;
			b[e]=a[i];
		}else{
			s--;
			b[s]=a[i];
		}
	}
	if (n%2==0){
		for (int i=s;i<=e;i++) cout<<b[i]<<' ';
	}else{
		for (int i=e;i>=s;i--) cout<<b[i]<<' ';
	}
	return 0;
}