// #include <bits/stdc++.h>
// using namespace std;
// const int M=110;
// typedef long long ll;
// char s[M];


// dp0[i][j]=dp0[i-1][j]*s[i]+dp[i-1][j-1]+s[]
// int main(int argc, char const *argv[])
// {
// 	scanf("%s",s+1);
// 	int k;cin>>k;
// 	int len=strlen(s+1);
// 	ll ans=0;
// 	if(k==1){
// 		ans=(len-1)*9+s[1]-'0';
// 	}
// 	else if(k==2){
// 		for(int i=1;i<=len;i++){
// 			for(int j=i+1;j<=len;j++){
// 				int aa=s[i]-'0';
// 				int bb=s[j]-'0';
// 				if(i==1)
// 					ans+=(aa-1)*9+bb;
// 				else
// 					ans+=81;
// 			}
// 		}
// 	}
// 	else{
// 		for(int i=1;i<=len;i++){
// 			for(int j=i+1;j<=len;j++){
// 				for(int z=j+1;z<=len;z++){
// 					if(i==1){
// 						int aa=s[i]-'0';
// 						int bb=s[j]-'0';
// 						int cc=s[z]-'0';
// 						ans+=(aa-1)*81+bb*cc;
// 					}
// 					else
// 						ans+=9*9*9;
// 				}
// 			}
// 		}
// 	}
// 	cout<<ans<<endl;
// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;
const int M=110;
char s[M];
int dp[M][5][3];
int main(int argc, char const *argv[])
{
	scanf("%s",s+1);
	int k;cin>>k;
	int len=strlen(s+1);
	dp[1][0][0]=1;
	dp[0][0][0]=1;
	for(int i=1;i<=len;i++){
		for(int j=0;j<=3;j++){//j个非零数字
			for(int p=0;p<2;p++){//p=0表示一定小于
				int num=s[i]-'0';
				for(int d=0;d<=9;d++){
					int ni=i+1,nj=j,np=p;
					if(d!=0)nj++;
					if(nj>k)continue;
					if(np==0){
						if(d>num)continue;
						if(d<num)np=1;
					}
					dp[ni][nj][np]+=dp[i][j][p];
				}
			}
		}
	}
	cout<<dp[len+1][k][0]+dp[len+1][k][1]<<endl;
	return 0;
}