#include<cstdio>
#include<algorithm>
using namespace std;

long long arr[55];
long long stu[55];
long long ans = 0;
int n;
long long x;
void f(int d){
    if(x==arr[d]){
        ans += stu[d];
        return ;
    }else if(x){
        x--;// 吃掉最底层的 b
        if(x>arr[d-1]){
            x-=arr[d-1];
            ans += stu[d-1];
            x--;
            ans++;
            if(x)f(d-1);
        } else f(d-1);
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
        arr[i] = arr[i-1]*2+3;
        stu[i] = stu[i-1]*2+1;
    }
    scanf("%d%lld",&n,&x);
    f(n);
    printf("%lld\n",ans);
    return 0;
}
