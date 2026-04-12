#include<bits/stdc++.h>
#define testbit(mask,i) (((mask)>>(i))&1)
#define setbit(mask,i) ((mask)|(1<<i))
#define delbit(mask,i) ((mask)^(1<<i))
#define lowbit(x) ((x)&(-x))
#define randome_generate srand(std::chrono::high_resolution_clock::now().time_since_epoch().count())
using namespace std;
string n;
int k;
long long dp[120][4];//开头不为零
long long pd[120][4];//开头为零 
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>k;
	int dig=n.size();
	n="?"+n;
	for(int i=1;i<=dig;i++){
		dp[i][1]=9LL;
		dp[i][2]=(long long)(i-1)*81LL;
		dp[i][3]=(long long)(i-1)*(long long)(i-2)/2LL*729LL;
	}
	for(int i=1;i<=dig;i++){
		pd[i][0]=1LL;
		for(int j=0;j<i;j++){//不为零的位数 
			pd[i][1]+=dp[j][1];
			pd[i][2]+=dp[j][2];
			pd[i][3]+=dp[j][3];
		}
	}
	int nzr=0;
	long long res=0LL;
	for(int i=1;i<=dig;i++){
		//1~i-1:same as n
		//i:<n
		if(n[i]!='0'){
			//1.==0
			res+=pd[dig-i+1][k-nzr];
			//2.!=0
			res+=dp[dig-i+1][k-nzr]/9LL*(long long)(n[i]-'0'-1);
			nzr++;
		}
		if(nzr>k)
			break;
	}
	if(nzr==k)
		res+=1LL;
	cout<<res<<endl;
	return 0;
}
