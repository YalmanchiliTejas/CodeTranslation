#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;

template<class T> inline void checkmin(T &a,const T &b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,const T &b){if(b>a) a=b;}

const int inf=1e9+10;

int n;

int main(){
	cin>>n;
	if(n>=30) cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}
