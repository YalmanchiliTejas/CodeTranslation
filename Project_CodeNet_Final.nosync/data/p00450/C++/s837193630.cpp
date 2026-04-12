#include<cstdio>
#include<math.h>
#include<algorithm>
#include<string.h>

using namespace std;
const int INF =1001001001;
#define rep(i,n) for(int i=0;i<n;i++)
int N;



int main(){
	scanf("%d",&N);
	do{
		pair<bool,int> Rs[100000];//色と連続している個数
		int cursol=-1;//今のRS内での要素番号
		rep(i,N){
			int a;
			scanf("%d",&a);
			if(i==0){Rs[++cursol]=make_pair(a,1);continue;}
			if(i%2){   //iが偶数
				if(a==Rs[cursol].first)Rs[cursol].second++;//右端と一致
				else{
					if(cursol>0){Rs[--cursol].second+=Rs[cursol+1].second+1;Rs[cursol+1].second=0;}
					else{Rs[cursol].first=a;Rs[cursol].second+=1;}
				}
			}else{      //iが奇数・・・そのまま置く
				if(a==Rs[cursol].first)Rs[cursol].second++;
				else{Rs[++cursol].first=a;Rs[cursol].second=1;}
			}
		}
		int ans=0;
		rep(i,cursol+1){
			if(Rs[i].first==0)ans+=Rs[i].second;
		}
		printf("%d\n",ans);
		scanf("%d",&N);
	}while(N);
	return 0;
}