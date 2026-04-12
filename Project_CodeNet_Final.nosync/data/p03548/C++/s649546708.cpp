#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int main(){
	int n,m,k;
	while (~scanf ("%d%d%d",&n,&m,&k)){
		int cont=(n-k)/(m+k);
		printf ("%d\n",cont);
	}
	return 0;
}