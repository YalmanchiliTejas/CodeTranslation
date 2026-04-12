#include<iostream>
#include<algorithm>
using namespace std;
long long int MAX(long long int a,long long int b)
{
    if(a>=b)
    return a;
    else
    return b;
}
int main()
{
    long long int n;
    scanf("%lld",&n);
    long long int a[n];
    for(int i=0;i<n;i++)
    scanf("%lld",&a[i]);
sort(a,a+n);
long long int l=a[n-1]; //left
long long int r=l;             // right
long long int i=0,j=n-2;
long long int sum=0;
while(i<j){
        int li=abs(l-a[i]),ri=abs(r-a[i]);
        int lj=abs(l-a[j]),rj=abs(r-a[j]);
        if(li>ri||lj>rj){ //left side
                if(li>lj){
                        sum+=li;
                        l=a[i++];
                }else{
                        sum+=lj;
                        l=a[j--];
                }
        }else{
                if(ri>rj){
                        sum+=ri;
                        r=a[i++];
                }else{
                        sum+=rj;
                        r=a[j--];
                }
        }
}
sum+=MAX(abs(l-a[i]),abs(r-a[i]));
cout<<sum<<endl;
}