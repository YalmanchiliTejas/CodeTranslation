#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

string n;
int k,inf[2]= {-1,-1};
__int128 ans=0;

inline __int128 comb(const int &v,const int &l) {
	if(l<v) return 0;
	if(!v) return 1;
	if(v==1) return 9*l;
	return 81*l*(l-1)/2;
}

inline void qw(const __int128 &x) {
	if(x>9) qw(x/10);
	putchar(x%10+48);
	return ;
}

int main() {
	cin>>n>>k;
	for(int i=1; i<n.length(); ++i)
		if(n[i]!=48) {
			if(inf[0]==-1) inf[0]=i;
			else {
				inf[1]=i;
				break;
			}
		}
	for(int i=k,x,y; i<=n.length(); ++i) {
		if(i!=n.length()) ans+=9*comb(k-1,i-1);
		else {
			if(k==1) {
				ans+=n[0]-48;
				break;
			}
			ans+=(n[0]-49)*comb(k-1,i-1);
			if(inf[0]==-1) break;
			if(k==2) {
				ans+=n[inf[0]]-48+comb(1,n.length()-inf[0]-1);
				break;
			}
			ans+=comb(2,n.length()-inf[0]-1)+(n[inf[0]]-49)*comb(1,n.length()-inf[0]-1);
			if(inf[1]==-1) break;
			ans+=n[inf[1]]-48+comb(1,n.length()-inf[1]-1);
		}
	}
	qw(ans),putchar('\n');
	return 0;
}