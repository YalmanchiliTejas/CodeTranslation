#include<iostream>
#include<algorithm>
#include<functional>
#include<stack>
#include<vector>
#include<list>
#include<map>
#include<queue>
#include<cstring>
#include<deque>

//----------------------------------------
#define mrepp(i,n,x) for(int i = n-1; i >= x; i--)
#define mrep(i,n) mrepp(i,n,0)
#define repp(i,x,n) for(int i =x; i < n; i++)
#define rep(i,n) repp(i,0,n)

using namespace std;
//----------------------------------------


int main(void){
	for(int N; cin >> N && N;){
		int t[100];
		rep(i,N)
			cin >> t[i];
		sort(t,t+N);
		
		int to = 0;
		repp(i,1,N-1){
			to += t[i];
		}
		
		cout << to/(N-2) << endl;
	}
	
	return 0;
}