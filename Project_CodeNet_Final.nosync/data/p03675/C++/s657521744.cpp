#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;

int main(){
	int N;
	cin>>N;
	bool f=false;
	deque<int> deq;
	REP(i,N){
		int a;
		cin>>a;
		if (!f){
			deq.push_back(a);
		}else{
			deq.push_front(a);
		}
		f=!f;
	}
	REP(i,N){
		int v;
		if (!f){
			v=deq.front();
			deq.pop_front();
		}else{
			v=deq.back();
			deq.pop_back();
		}
		if (i){
			cout<<" ";
		}
		cout<<v;
	}
	cout<<endl;
	return 0;
}