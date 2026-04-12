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
long long n,k,cnt;
int main(){
	cin>>n>>k;
	for (int i=1;i<=int(n);i++){
		cnt+=ll(n/i*max(0ll,i-k));
		if (n%i!=0) cnt+=ll(max(0ll,n%i-ll(max(k,1ll))+1));
	}
	cout<<cnt;
	return 0;
}