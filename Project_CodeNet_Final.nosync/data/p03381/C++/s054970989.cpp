#include<algorithm>
#include<bitset>
#include<cctype>
#include<cstring>
#include<cstdlib>
#include<deque>
#include<fstream>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<math.h>
#include<queue>
#include<set>
#include<stack>
#include<stdio.h>
#include<sstream>
#include<string>
#include<time.h>
#include<utility>
#include<vector>

using namespace std;

int n;
int A[200005],B[200005];

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",A+i);
		B[i]=A[i];
	}
	sort(A,A+n);
	int md1=A[n/2-1];
	int md2=A[n/2];
	for(int i=0;i<n;i++){
		if(B[i]>md1) printf("%d\n",md1);
		else printf("%d\n",md2);
	}
	return 0;
}
