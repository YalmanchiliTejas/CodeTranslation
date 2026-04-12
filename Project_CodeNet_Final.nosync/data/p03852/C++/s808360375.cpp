
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#define  rep(i,a,b)for(int i=a;i<b;++i)
#define  rrep(i,a,b)for(int i=a;i>b;--i)
#define  yesno(flag)if(flag)cout<<"Yes"<<endl; else cout<<"No"<<endl;
using namespace std;
typedef long long ll;
const ll INF=100000000000LL;
const ll r197=1000000007;
typedef pair<int,int>P;
int main() {
	char a;
	cin>>a;
	if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u')cout<<"vowel"<<endl;
	else cout<<"consonant"<<endl;
	return 0;
}
