/*input
6
0 6 7 6 7 0
*/
#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
long long a[1000005],n;

int main(){
	ios_base::sync_with_stdio(0);
	long long q,m,k,h,ans=0,sum=0,p,x=0,y;
	cin>>n;
	for(int i=0;i<n;cin>>a[i++]);
	deque<int> v;
	for(int i=0;i<n;++i){
		if(x==0) v.push_back(a[i]);
		else v.push_front(a[i]);
		x^=1;
	}
	if(x==0) for(int i:v) cout<<i<<" ";
	else{
		stack<int> s;
		for(int i:v) s.push(i);
		while(!s.empty()) {
			cout<<s.top()<<" ";
			s.pop();
		}
	}
}