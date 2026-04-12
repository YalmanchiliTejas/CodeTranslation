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
	int r,g,b;
	cin>>r>>g>>b;
	if((2*g+b)%4==0)cout<<"YES";
	else cout<<"NO";
}