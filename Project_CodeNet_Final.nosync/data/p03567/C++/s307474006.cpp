#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <set>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

using namespace std;
typedef long long int lli;

int main(){
	string S;
	cin>>S;
	int l=(int)S.length();
	bool ac=false;
	rep(i,l-1)if(S[i]=='A'&&S[i+1]=='C')ac=true;
	if(ac)cout<<"Yes";
	else cout<<"No";
}