#include <stdio.h>
const int N=1e5+10;
int main(){
    int n,a[N],l,r,mid,q,temp;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    scanf("%d",&q);
    while(q--){
        scanf("%d",&temp);
        if(a[n-1]<temp)printf("%d\n",n);
        else if(a[0]>=temp)printf("0\n");
        else{
            l=0;
            r=n-1;
            while(r-l>1){
                mid=(r+l)>>1;
                if(a[mid]>=temp)r=mid;
                else l=mid;
            }
            printf("%d\n",r);
        }
    }
}
