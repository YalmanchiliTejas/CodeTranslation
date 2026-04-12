#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <memory.h>
using namespace std;

int ans[200005];

int main(){
	int n;
	scanf("%d",&n);
	int id1=n/2+1,id2=id1-1,id=0,m=n;
	if(n%2) id1=n/2+2,id2=id1-1,id=1; 
	while(m){
		int x;
		scanf("%d",&x);
		if(id%2) {
			ans[id2]=x;
			id2--;
		}
		else {
			ans[id1]=x;
			id1++;
		}
		id++;
		m--;
	}
	for(int i=1;i<=n;i++) {
		if(i-1) printf(" ");  
		printf("%d",ans[i]);
	} 
	printf("\n");
return 0;
}