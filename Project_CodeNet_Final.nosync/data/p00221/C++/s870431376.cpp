#include <iostream>
#include <sstream>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int m, n, nx[1000], pr[1000];
string fizz[10000];

int main() {
	rep(i, 10000) {
		int k=i+1;
		ostringstream sout;
		if(k%3 && k%5) sout << k;
		if(k%3==0) sout << "Fizz";
		if(k%5==0) sout << "Buzz";
		fizz[i] = sout.str();
	}
	while(cin>>m>>n) {
		if(m==0) break;
		rep(i, m) nx[i]=(i+1)%m;
		rep(i, m) pr[i]=(i+m-1)%m;
		int cur=0;
		rep(i, n) {
			string s;
			cin >> s;
			if(cur==nx[cur]) continue;
			if(s!=fizz[i]) {
				nx[pr[cur]]=nx[cur];
				pr[nx[cur]]=pr[cur];
			}
			cur=nx[cur];
		}
		while(cur<nx[cur]) cur=nx[cur];
		for(int s=nx[cur]; s!=cur; s++) printf("%d ", s+1);
		printf("%d\n", cur+1);
	}
	return 0;
}