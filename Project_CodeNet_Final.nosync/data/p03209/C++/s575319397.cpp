#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int N;
long long X;
long long a[51],b[51];

long long f(int N,long long X){
	if(N == 0)return 1;
	else if(X == 1 ) return 0;
	else if(X == b[N])return a[N];

	else if(X <= 1+b[N-1])return f(N-1,X-1);

	else if(X == 2+b[N-1])return 1+f(N-1,X-2);
	
	else return 1+a[N-1]+f(N-1,X-2-b[N-1]);

}
int main(){
	cin >> N >> X;
	a[0]=1;
	b[0]=1;
	for(int i=1;i<51;i++)a[i]=1+2*a[i-1];
	for(int i=1;i<51;i++)b[i]=3+2*b[i-1];

	cout << f(N,X) << endl;
	return 0;
}