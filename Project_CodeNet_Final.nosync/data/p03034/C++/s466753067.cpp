#include"bits/stdc++.h"
using namespace std;
#define LL long long
#define PB push_back
#define MP make_pair

int N;
LL s[100000];

int main(){
	cin >> N;
	for(int i=0; i<N; i++) cin >> s[i];
	LL ans = 0;
	for(int D=1; D<N; D++){
		bool visited[100000] ={};
		int l = 0;
		int r = N-1;
		LL sum = 0;
		while(l+D < N && r-D >= 0){
			if(visited[l]) break;
			visited[l] = true;
			if(visited[r]) break;
			visited[r] = true;
			sum += s[l];
			sum += s[r];
			ans = max(ans, sum);
			l += D;
			r -= D;
		}
	}
	cout << ans << endl;
}
