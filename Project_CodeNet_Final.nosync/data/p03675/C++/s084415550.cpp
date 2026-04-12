#include <bits/stdc++.h>
#define REP(i,n,N) for(int i=(n);i<(int) N;i++)
#define RREP(i,n,N) for(int i=N-1;i>=(int) n;i--)
#define p(s) cout<<(s)<<endl
#define DEBUG(x,y) cout<<#x<<": "<<x<<" , "<<#y<<": "<<y<<endl;
#define CK(n,a,b) ((a)<=(n)&&(n)<=(b))
#define F first
#define S second
typedef long long ll;
using namespace std;
const ll inf=1e9;



int main(){
	int n;
	cin>>n;
	deque<int> dq;
	REP(i,0,n){
		int a;
		cin>>a;
		if(i%2==1) dq.push_front(a);
		else dq.push_back(a);
	}
	bool flag=false;
	if(n%2==1)reverse(dq.begin(),dq.end());
	for(auto itr=dq.begin();itr!=dq.end();itr++){
		if(!flag){
			cout<<*itr;
			flag=true;
		}
		else cout<<" "<<*itr;
	}
	p("");
	return 0;
}
