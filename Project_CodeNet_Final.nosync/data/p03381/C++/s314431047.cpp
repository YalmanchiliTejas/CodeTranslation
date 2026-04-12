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
typedef long long ll;
using namespace std;
int n,a[200005],b[200005];
int main(){
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b,b+n);
	int l=b[n/2-1],r=b[n/2];
	for (int i=0;i<n;i++){
		if (a[i]<=l){
			cout<<r<<endl;
		}else{
			cout<<l<<endl;
		}
	}
} 