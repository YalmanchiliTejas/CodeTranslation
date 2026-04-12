#include <iostream>
#include <ios> 
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <set>
#include <cmath>
#include <map>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

using namespace std;
typedef long long int lli;


lli pt(int a, lli f){
  	if(f==0) return 0;
  	if(a==0) return 1;
	if(f<=pow(2, (lli)a+1)-2) return pt(a-1, f-1);
	return pt(a-1, f-pow(2,(lli)a+1)+1)+pow(2,a);
}

int main(){
	int N;
	lli X;
	cin>>N>>X;
	lli ans=pt(N,X);
	cout<<ans;
}