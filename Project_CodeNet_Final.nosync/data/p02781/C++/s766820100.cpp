#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
typedef map<int,int> ma;
typedef set<int> se;
typedef vector<int> ve;
const int maxn=1e2+7;
char a[107];
int K;
int dp[111][2][4];
int solve1(){
    int s=strlen(a);
    dp[0][0][0]=1;
    for(int i=0;i<s;i++)
	{
		for(int j=0;j<2;j++)
		{
			int lim=j?9:a[i]-'0';
			for(int k=0;k<=K;k++)
			{
				for(int l=0;l<=lim;l++)
				{
					int nk=k+!!l;
					if(nk<=K)
					{
						dp[i+1][j||l<lim][nk]+=dp[i][j][k];
					}
				}
			}
		}
	}
	///printf("%d\n",dp[s][0][K]+dp[s][1][K]);
	return dp[s][0][K]+dp[s][1][K];
}
int solve2(){
    int sum=0;
    int s=strlen(a);
    if(K==1){
        for(int i=0;i<s;i++){
            int x=a[i]-'0';
            if(i!=0)
                x=9;
            sum+=x;
        }
    }
    else if(K==2){
        int f=0;
        for(int i=0;i<s;i++){
            for(int j=i+1;j<s;j++){
                int x=a[i]-'0',y=a[j]-'0';
                if(f){
                    y=9;
                    if(i!=0)
                        x=9;
                }
                if(a[j]-'0') f=1;
                sum+=max(0,(x-1)*9+y);
            }
            f=1;
        }
    }
    else {
        int f1=0,f2=0;
        for(int i=0;i<s;i++){
            for(int j=i+1;j<s;j++){
                for(int p=j+1;p<s;p++){
                    int x=a[i]-'0',y=a[j]-'0',z=a[p]-'0';
                    if(f1){
                        z=9;
                        if(i!=0)
                            x=9;
                        if(f2) y=9;
                    }

                    if(a[p]-'0') f1=1;
                    sum+=max(0,(x-1)*81)+max(0,(y-1)*9+z);
                    //sum+=max(0,(x-1)*81+(y-1)*9+z);
                }
                if(a[j]-'0') f1=f2=1;
                f1=f2;
            }
            f1=f2=1;
        }
    }
    printf("%d\n",sum);
    return sum;
}
int main() {
    scanf("%s%d",a,&K);
    solve2();
//    while(1){
//
//        memset(dp,0,sizeof dp);
//
//        int t=5;
//        //scanf("%s",a);
//        for(int i=0;i<t;i++)
//           a[i]=rand()%10+'0';
//        if(a[0]=='0') a[0]++;
//        a[t]=0;
//
//        K=3;
//        int t1=solve1(),t2=solve2();
//        if(t1!=t2){
//            printf("************************\n");
//            printf("%s\n",a);
//            printf("%d %d\n",t1,t2);
//            printf("************************\n");
//            //while(1);
//        }
//    }


	return 0;
}



/**********************

740948824551711527614232216857618927954312

*********************/
