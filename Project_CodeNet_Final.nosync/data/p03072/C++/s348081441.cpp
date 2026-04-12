#include <cstdio>

using namespace std;
 
int main() {
    int n,m[20],p=0,q=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&m[i]);
        if(m[i]>=q){
            q=m[i];
            p++;
        }
    }
    printf("%d",p);
    return 0;
}