#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define maxn 200005
using namespace std;
int a[maxn];
int n;
int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for (int i = n - 1; i >=0 ; i -= 2){
        printf("%d ",a[i]);
    }
    for (int i = (n & 1) ? 1 : 0; i < n; i += 2){
        printf("%d ", a[i]);
    }
    return 0;
}