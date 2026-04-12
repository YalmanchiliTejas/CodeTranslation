#include<cmath>
#include<bits/stdc++.h>
#define MAX(a,b) (a>b? a:b)
#define MIN(a,b) (a>b? b:a)
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repr(i,n) for(lint i=(lint)(n);i>0;--i)
#define reps(i,a,b) for(lint i=a;i<=(lint)(b);i++)
typedef long long lint;
typedef long double ld;
using namespace std;
const ld PI = acos(-1.0);

int main(){
	int x;
	cin >> x;
	if(x==3||x==5||x==7) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}