#include<cstdio>
#include<algorithm>
using namespace std;
 long long arr[55];
long long stu[55];
long long ans = 0;
int n;
 long long x;
 void f(int d){
     if(x==arr[d]){//如果吃x层会整好吃完级别为 d 的汉堡
         ans += stu[d];
         return ;
     }else if(x){
         x--;// 吃掉最底层的 b
         if(x>arr[d-1]){// x 落在了上面的 L-1 级的汉堡
             x-=arr[d-1];//吃掉下面的 L-1 级的汉堡
             ans += stu[d-1];// L-1级别的汉堡有stu[l-1]层 p
            x--;// 吃掉中间的 p
             ans++;
             if(x)f(d-1);// 进入上面的 L-1 级的汉堡
             //这里可以不进行if判断直接进入 因为进入后还会判断x非零
         } else f(d-1);// 落点在下面的 L-1 级汉堡
     }
 }
 int main(){
     arr[0] = 1;
     arr[1] = 5;
     arr[2] = 13;
     stu[0] = 1;
     stu[1] = 3;
    stu[2] = 7;
     for(int i=3;i<51;i++){
         //arr[i] = 1+arr[i-1]+1+arr[i-1]+1;
         arr[i] = arr[i-1]*2+3;// 级别为 i 的汉堡的层数 b+p
         stu[i] = stu[i-1]*2+1;// 级别为 i 的汉堡的 p 的数量
     }
     scanf("%d%lld",&n,&x);
     f(n);
     printf("%lld\n",ans);
     return 0;
 }