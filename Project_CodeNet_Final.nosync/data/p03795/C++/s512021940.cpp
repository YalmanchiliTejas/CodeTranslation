#include<bits/stdc++.h>
#define IN(n) cin>>n
#define OUT(n) cout<<n
#define CAL1(a,b) a*b
#define CAL2(a,b) floor(a/b)
#define CAL3(a,b) a-b
using namespace std;
int n; 
int x,y;
int main(){
	IN(n);
	x=CAL1(n,800);
	y=CAL1(CAL2(n,15),200);
	OUT(CAL3(x,y)),OUT(endl);
	return 0;
}