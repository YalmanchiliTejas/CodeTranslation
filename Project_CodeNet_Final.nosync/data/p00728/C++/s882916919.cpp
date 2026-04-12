#include<cstdio>

#define INF 1e9
#define llINF 1e18
#define MOD 1e9+7
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
using namespace std;
int main(){
  int n,i;
  while(true){
    int num[500],max=0,min=100000000,sum=0;
    scanf("%d",&n);
    if(n==0)break;
    for(i=0;i<n;i++){
      scanf("%d",&num[i]);
      if(num[i]<min)
	min=num[i];
      if(num[i]>max)
	max=num[i];
    }
    for(i=0;i<n;i++)
      sum+=num[i];
    sum=sum-max-min;
    printf("%d\n",sum/(n-2));
  }
  return 0;
}

