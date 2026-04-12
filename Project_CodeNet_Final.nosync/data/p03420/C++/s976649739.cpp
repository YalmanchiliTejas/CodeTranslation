//writer：Sakura
//problem：Remainder Reminder
//id：arc091_D
//from：AtCoder

#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//double i=2,j=3;
	ll ans=0;
	//cout<<i<<" "<<j<<endl;
	/*while(i<j && i<=N && j<=N){
		//cout<<i%j<<endl;
		//cout<<i<<" "<<j<<endl;
		if(i%j>=K){
			//cout<<i<<" "<<j<<endl;
			//cout<<i/j<<endl;
			if(j%i>=K)ans++;
			ans++,j++;
			if(i<=N && j>N){
				i++,j--;
			}
		}
		else i++,j--;
		//if(j<N && i>=N)break; 
	}*/
	//cout<<i<<" "<<j<<endl;
	int n,k;
	scanf("%d %d",&n,&k);
	if (k==0){
		for(int b=1;b<=n;b++)
			ans+=n/b*b+n%b;
		printf("%lld\n", ans);
		return 0;
	}
	for (int b=k+1;b<=n;b++){
		ans+=b-k;
		for (int i=1;(i+1)*b<=n;i++)
			ans+=b-k;
		if(n%b!=0 && n>b) ans+=max(0,n%b-k+1);
	}
	printf("%lld\n",ans);
	return 0;
}
