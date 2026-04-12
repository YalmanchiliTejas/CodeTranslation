#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)

int main(){
	int n;
	scanf("%d", &n);
	deque<int> q;
	f(i, 0, n){
		int t;
		scanf("%d", &t);
		if (i & 1)q.push_back(t);
		else q.push_front(t);
	}
	if (!(n & 1))while (!q.empty()){
		printf("%d", q.back());
		q.pop_back();
		if (!q.empty())printf(" ");
	}else while (!q.empty()){
		printf("%d", q.front());
		q.pop_front();
		if (!q.empty())printf(" ");
	}
}