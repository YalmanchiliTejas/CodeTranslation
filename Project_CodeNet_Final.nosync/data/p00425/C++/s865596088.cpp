#include <iostream>
using namespace std;

#define repi(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) for(int i=0;i<(n);i++)

int main() {
	ios::sync_with_stdio(false);
	
	int n, s;
	int u, f, r, q;
	char w[6];
	
	while(cin>>n,n) {
		s=1;q=0;
		u=1;f=2;r=3;
		
		rep(i, n) {
			cin>>w;
			switch(w[0]) {
				case 'N':
					q=u;
					u=f;
					f=7-q;
					break;
				case 'E':
					q=r;
					r=u;
					u=7-q;
					break;
				case 'W':
					q=u;
					u=r;
					r=7-q;
					break;
				case 'S':
					q=f;
					f=u;
					u=7-q;
					break;
				case 'R':
					q=f;
					f=r;
					r=7-q;
					break;
				case 'L':
					q=r;
					r=f;
					f=7-q;
					break;
				default:
					break;
			}
			s+=u;
		}
		cout<<s<<endl;
	}
	
	return 0;
}