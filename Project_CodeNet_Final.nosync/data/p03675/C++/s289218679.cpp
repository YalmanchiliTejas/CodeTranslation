#include <iostream>
#include <vector>
#include <deque>
using namespace std; using P=pair<int,int>; using ll=long long;
const int mx=1e5; vector<vector<int>> v(mx); vector<int> c(mx); int n; bool noco=false;

int main() {
	int n; cin>>n;
	deque<int> que;
	for(int i=0;i<n;i++) {
		int a; cin>>a;
		if (i%2==0) que.push_back(a);
		else que.push_front(a);
	}
	int tp;
	for(int i=0;i<n;i++) {
		if (n%2==0) tp=que.front(), que.pop_front();
		else tp=que.back(), que.pop_back();
		cout<<tp<<" ";
	} cout<<endl;
}