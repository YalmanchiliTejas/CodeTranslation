/*#### bits/stdc++.h */
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<map>
#include<set>
#include<vector>
#include<deque>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
/*####*/
int main(){
	char s[99];
	scanf("%s",s);
	int n = strlen(s);
	for(int i=0; i+1<n; i++)
		if(s[i] == 'A' && s[i+1] == 'C'){
			puts("Yes");
			return 0;
		}
	puts("No");
	return 0;
}
