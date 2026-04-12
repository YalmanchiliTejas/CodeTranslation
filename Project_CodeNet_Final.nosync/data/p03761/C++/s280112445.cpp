#include <iostream>
#include <climits>
#include <stack>
#include <queue>
#include <string>
#include <utility>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int INF = 1<<29;
double Pi = 3.141592653589;
const int mod = 1000000007;
// memset(a,0,sizeof(a)); →全部０にする

long long int i,j;

long long int solve(long long int a,long long int b,long long int c){
	return max(a,max(b,c))-min(a,min(b,c));
}

int main(){
	int n,m;
	cin>>n;
	char s[53];
	int zenbu[28],ima[28];
	for(i=0;i<26;i++){
		zenbu[i]=INF;
	}
	for(i=0;i<n;i++){
		cin>>s;
		m=strlen(s);
		memset(ima,0,sizeof(ima));
		for(j=0;j<m;j++){
			ima[s[j]-'a'] += 1;
		}
		for(j=0;j<26;j++){
			zenbu[j]=min(zenbu[j],ima[j]);
		}
	}
	int k=0,mozi;
	char ans[55];
	for(i=0;i<26;i++){
		mozi=zenbu[i];
		for(j=0;j<mozi;j++){
			ans[j+k] = i+'a';
		}
		k += mozi;
	}
	n=strlen(ans);
	for(i=0;i<k;i++){
		cout<<ans[i];
	}
	cout<<endl;
	//output
	return 0;
}