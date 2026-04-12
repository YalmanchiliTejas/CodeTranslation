                                            
  //File Name: A.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月13日 星期日 20时10分44秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 10;
char a[MAXN];
int main(){
	int n,m,s = 0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%s",a);
		for(int j=0;j<m;j++)
			if(a[j] == '#')
				s++;
	}
	if(s == n + m - 1) puts("Possible");
	else puts("Impossible");
	return 0;
}