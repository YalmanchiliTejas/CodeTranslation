#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define LL long long
#define st first
#define nd second
#define endl '\n'
using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,t;
	cin>>n;
	deque<int> q;
	for(int i=0;i<n;++i) {
		cin>>t;
		if(i%2==0) {
			q.push_back(t);
		}
		else q.push_front(t);
	}
	if(n==2) {
		for(int i=0;i<n;++i) {
			cout<<q.back()<<" ";
			q.pop_back();
		}
	}
	else if(n%2==0) {
		for(int i=0;i<n;++i) {
			cout<<q.front()<<" ";
			q.pop_front();
		}
	}
	else {
		for(int i=0;i<n;++i) {
			cout<<q.back()<<" ";
			q.pop_back();
		}
	}

}
