#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <set>
#include <cmath>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

using namespace std;
typedef long long int lli;
const int MAX=2e5;

int main(){
	int N;
	cin>>N;
	int X[MAX],Y[MAX];
	rep(i,N){cin>>X[i];Y[i]=X[i];}
	sort(Y,Y+N);
	int a=Y[N/2-1];
	int b=Y[N/2];
	rep(i,N){
		if(X[i]<=a)cout<<b<<endl;
		else cout<<a<<endl;
    }
}