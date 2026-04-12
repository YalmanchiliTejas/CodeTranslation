#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<set>
#include<stack>
#include<queue>
using namespace std;
const int maxn  = 200000;
long long n,ans;
long long num[maxn];
int main(){
	scanf("%lld",&n);
	for(int i = 1; i <= n ; i++){
		scanf("%lld",&num[i]);
	}
	sort(num + 1, num+ n + 1);
	if(n&1){
		long long temp1 = 0,tem1 = 0,ans1 = 0;
		long long temp2 = 0,tem2 = 0,ans2 = 0;
		int t1 = n / 2 + 1;
		for(int i = 1 ;i <= t1 ; i++) temp1 += 2*num[i];
		for(int i = t1 + 1 ; i <= n ; i++) tem1 += 2*num[i];
		ans1 = tem1 - temp1 + num[t1] + num[t1 - 1];
		int t2 = n/2; 
		for(int i = 1 ; i <= t2 ; i++) temp2 += 2*num[i];
		for(int i = t2 + 1 ; i <= n ; i++) tem2 += 2*num[i];
		ans2 = tem2 - temp2 - num[t2 + 1] - num[t2 + 2];
		ans = max(ans1,ans2);	
	}else{
		long long t = n/2;
		long long tem = 0,temp = 0;
		for(int i = 1 ; i <= t ; i++) temp += 2*num[i];
		for(int i = t + 1 ; i <= n ; i++) tem += 2 * num[i];
		ans = tem - temp - num[t + 1] + num[t];
	}
	printf("%lld\n",ans);
	return 0;
}