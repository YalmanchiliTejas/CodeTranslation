#include <stdio.h>
#define ull unsigned long long
#define maxn 505
int s[maxn],t[maxn],br[maxn],bc[maxn],cnt[maxn],a[maxn][maxn];//s[0]:row,and;s[1]:row:or.t[0]:col,and;t[1]:col,or;
ull u[maxn],v[maxn],ans[maxn][maxn];
int main(){
	int i,j,n,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&s[i]);
	for(i=1;i<=n;i++)scanf("%d",&t[i]);
	for(i=1;i<=n;i++)scanf("%llu",&u[i]);
	for(i=1;i<=n;i++)scanf("%llu",&v[i]);
	for(k=0;k<64;k++){//逐位判定，状压
		for(i=1;i<=n;i++)br[i]=((u[i]>>k)&1),bc[i]=((v[i]>>k)&1);//获得第k位上的值
		int hr[4]={0,0,0,0},hc[4]={0,0,0,0};//hr{(row,and,0),(row,and,1),(row,or,0),(row,or,1)}统计数量
		for(i=1;i<=n;i++)//行列计算
			hr[s[i]*2+br[i]]++,hc[2*t[i]+bc[i]]++;//hc{(col,and,0),(col,and,1),(col,or,0),(col,or,1)}
		if(hr[2]&&hc[1])return 0*printf("-1\n");//粗筛(row,or,0),(col,and,1),两者不能同时有取值
		if(hc[2]&&hr[1])return 0*printf("-1\n");//粗筛(col,or,0),(row,and,1),两者不能同时有取值
		for(i=1;i<=n;i++){//用行操作后的值，来设定初值
			cnt[i]=n;//i行上，雷同的数据有n个
			for(j=1;j<=n;j++)
				a[i][j]=br[i];//可以这样设置的理由:1&1=1,0&0=0;1|1=1,0|0=0;
		}
		for(j=1;j<=n;j++)
			if(t[j]!=bc[j])
				for(i=1;i<=n;i++)
					if(a[i][j]!=bc[j])cnt[i]--,a[i][j]=bc[j];
		for(j=1;j<=n;j++){//用列操作后的值，来进行修补,全1,全0的情况在粗筛时，已做了判定
			int flag=0;//判定是否找到
			if(t[j]==bc[j]){//(col,and,0,0)或者(col,or,1,1)
				for(i=1;i<=n;i++)
					if(a[i][j]==bc[j]){flag=1;break;}
				if(flag)continue;//找到
				for(i=1;i<=n;i++)//继续找
					if(s[i]==br[i]&&cnt[i]>=2){//找同样类型的行
						cnt[i]--,a[i][j]=bc[j];
						break;
					}
			}
			//可能存在找不到，不要怕，之后会进行检验。
		}
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				ans[i][j]|=((ull)a[i][j]<<k);//生成 位上相应值
	}
	for(i=1;i<=n;i++){//行检验
		ull c=ans[i][1];
		for(j=2;j<=n;j++)
			if(s[i]==0)c=c&ans[i][j];
			else c=c|ans[i][j];
		if(c!=u[i])return 0*printf("-1\n");
	}
	for(j=1;j<=n;j++){//列检验
		ull c=ans[1][j];
		for(i=2;i<=n;i++)
			if(t[j]==0)c=c&ans[i][j];
			else c=c|ans[i][j];
		if(c!=v[j])return 0*printf("-1\n");
	}
	for(i=1;i<=n;i++){//经历了考验
		for(j=1;j<=n;j++)
			printf("%llu ",ans[i][j]);
		printf("\n");
	}
	return 0;
}