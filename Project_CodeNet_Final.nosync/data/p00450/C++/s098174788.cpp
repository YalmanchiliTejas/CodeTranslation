#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	int N;
	while(cin>>N,N){
		int dp[110000],stone,last=-1,ans=0;
		dp[0]=1;
        for(int i=1;i<=N;i++){
            cin>>stone;
            if(stone==0) ans++;
            if(last==stone){
                dp[i]=dp[i-1];
            }
            else{
                if(i%2==1){
                    dp[i]=i;
                }
                else{
                    if(stone==0){
                        ans+=i-dp[i-1];
                    }
                    else{
                        ans-=i-dp[i-1];
                    }
                    dp[i]=dp[dp[i-1]-1];
                }
            }
            last=stone;
        }
        printf("%d\n",ans);
	}
	return 0;
}