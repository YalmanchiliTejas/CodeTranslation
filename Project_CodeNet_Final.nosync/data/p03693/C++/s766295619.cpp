#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#define N 1000005
using namespace std;
typedef long long ll;
ll mod = 1000000007;
int main() {
	int r,g,b;
	cin>>r>>g>>b;
	int res=r*100+10*g+b;
	if (res%4==0) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}