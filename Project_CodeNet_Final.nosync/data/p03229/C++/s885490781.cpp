#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main(){
    long long int ans;
    int n;
    scanf("%d",&n);
    
    long long int a[n];
    int i;
    for(i=0;i<n;i++)scanf("%lld",&a[i]);
    
    long long int sa[n];
    for(i=0;i<n;i++)sa[i]=a[i];
    sort(sa,sa+n);
    
    long long int sum=0;
    long long int sum2=0;
    
    if(n%2==0){
        a[0]=sa[n/2];
        a[n-1]=sa[n/2-1];
        for(i=1;i<n-1;i++){
            if(i%2==1)a[i]=sa[(i-1)/2];
            if(i%2==0)a[i]=sa[n-i/2];
            if(i>0)sum+=abs(a[i]-a[i-1]);
            if(i==n-2)sum+=abs(a[i+1]-a[i]);
        }
    }else{
        a[0]=sa[(n-1)/2+1];
        a[n-1]=sa[(n-1)/2];
        for(i=1;i<n-1;i++){
            if(i%2==1)a[i]=sa[i/2];
            if(i%2==0)a[i]=sa[n-i/2];
            sum+=abs(a[i]-a[i-1]);
            if(i==n-2)sum+=a[i+1]-a[i];
        }
        for(i=0;i<n;i++)
        a[0]=sa[(n-1)/2];
        a[n-1]=sa[(n-1)/2-1];
        for(i=1;i<n-1;i++){
            if(i%2==0)a[i]=sa[(i-1)/2];
            if(i%2==1)a[i]=sa[n-1-i/2];
            sum2+=abs(a[i]-a[i-1]);
            if(i==n-2)sum2+=abs(a[i+1]-a[i]);
        }
    }
    if(sum>sum2){
        ans=sum;
    }else{
        ans=sum2;
    }
    if(n==2)ans=abs(a[1]-a[0]);
    printf("%lld\n",ans);

    return 0;
}