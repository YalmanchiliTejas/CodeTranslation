#include<cstdio>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
#include<cstring>
 
 
using namespace std;
#define int long long int
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define mp make_pair
#define pb push_back

char num[10000];
int K;
int ans0[105][10];
int ans1[105][10];
signed main(){
    scanf("%s",num);
    scanf("%lld",&K);
    int sz=strlen(num);
    //printf("%lld",sz);
    for(int i=0;i<sz;i++){
        int x=num[i]-'0';
        rep(j,4){
            ans0[i][j]=0;
            ans1[i][j]=0;
            if(i==0){//一番上のけたについて(1以上)
                //k<xにした時、確定
                ans0[i][1]=x-1;
                ans0[i][0]=1;
                //k==xにした時、非確定
                ans1[i][1]=1;
                continue;
            }
            if(i>0)rep(k,10){//iけためをkにしたとき
                //0にしたとき、0以外の個数が増えない
                if(k==0){
                    if(k<x){
                        ans0[i][j]+=ans0[i-1][j]+ans1[i-1][j];
                    }else if(k==x){
                        ans0[i][j]+=ans0[i-1][j];
                        ans1[i][j]+=ans1[i-1][j];
                    }else{
                        ans0[i][j]+=ans0[i-1][j];
                    }
                }else if(j>0){
                //0以外の数にしたとき、0以外の個数が増える
                    if(k<x){
                        ans0[i][j]+=ans0[i-1][j-1]+ans1[i-1][j-1];
                    }else if(k==x){
                        ans0[i][j]+=ans0[i-1][j-1];
                        ans1[i][j]+=ans1[i-1][j-1];
                    }else{
                        ans0[i][j]+=ans0[i-1][j-1];
                    }
                }
            }
        }
    }
    int ansminus=0;//000が含まれているが、引くかどうか
    printf("%lld\n",ans0[sz-1][K]+ans1[sz-1][K]);
    return 0;
}
