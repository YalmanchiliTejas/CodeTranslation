#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a;
ll b,ans=0;
ll arr[55];
ll brr[55];
void f(int c){
    if(b==brr[c]){
        ans += arr[c];
        return ;
    }
    else if(b){
        b--;
        if(b>brr[c-1]){
            b -= brr[c-1];
            ans += arr[c-1];
            b--;
            ans++;
            if(b)f(c-1);
        }
        else
            f(c-1);
    }

}

int main()
{
    arr[0]=1;//汉堡中肉饼的层数
    brr[0]=1;//汉堡中肉饼加面包的层数
    for(int i = 1;i < 51;i++){
        arr[i]=2*arr[i-1]+1;
        brr[i]=2*brr[i-1]+3;
    }
    scanf("%d %lld",&a,&b);
    f(a);
    printf("%lld\n",ans);
    return 0;
}
