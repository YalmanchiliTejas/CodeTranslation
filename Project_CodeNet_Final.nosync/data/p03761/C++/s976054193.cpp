#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
#include<cassert>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=500000004;
const long double EPS = 1e-14;
const long double INF = 1e+20;
const long double PI = acos(-1);
char S[100];
int mm[26];
int tmp[26];
int main(){
	for(int i=0;i<26;i++)mm[i]=mod;
 
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++){
		scanf("%s",S);
		for(int j=0;j<26;j++)tmp[j]=0;
		for(int j=0;S[j];j++)tmp[S[j]-'a']++;
		for(int j=0;j<26;j++)mm[j]=min(mm[j],tmp[j]);
	}
	for(int i=0;i<26;i++){
		for(int j=0;j<mm[i];j++)printf("%c",'a'+i);
		
	}printf("\n");
}