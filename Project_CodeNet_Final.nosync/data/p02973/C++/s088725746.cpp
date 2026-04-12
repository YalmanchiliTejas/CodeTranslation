#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue> //priority_queue 优先队列
#include <map>
#include <set> //multiset  set<int>::reverse_iterator rit; for(rit=s.rbegin();rit!=s.rend();rit++)
#include <vector>
#include <stack>
#include <cmath>
#include <utility>
#include <sstream>
#include <string>
#define mod 1000000007
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
const db eps=1e-6;
const int INF = 0x3f3f3f3f;
const ll inf=0x3f3f3f3f3f3f3f3f;
const int N=1e6+5;
using namespace std;

int n,m,ans,x;
vector<int > v;
vector<int> ::iterator it;

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		if(v.empty()){
			v.push_back(x);
		}else{
			it=upper_bound(v.begin(),v.end(),x,greater<int >());
			if(it==v.end()){
				v.push_back(x);
			}else{
				*it=x;
			}
		}
	}
	printf("%d\n",v.size());
	return 0;
}