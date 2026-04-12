#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int maxn=2e5+100;
LL a[maxn];
int n;
bool cmp(const LL x,const LL y){
    return x>y;
}
int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+1+n,cmp);
    vector<LL>b;
    int i=1,j=n;
    while(i<j){
        b.push_back(a[i]);
        b.push_back(a[j]);
        i++,j--;
    }
    if(n%2){
        b.push_back(a[(n+1)/2]);
    }
    LL sum1=0;
    for(int i=1;i<b.size();i++){
        sum1+=abs(b[i]-b[i-1]);
    }
    int len=b.size()-1;
    LL sum=abs(b[0]-b[len]);
   // cout<<sum<<endl;
    for(int i=1;i<len;i++){
        sum+=abs(b[i]-b[i-1]);
    }
    LL sum2=0;
    for(int i=1;i<len;i++){
        sum2+=abs(b[i]-b[i-1]);
    }
    sort(a+1,a+1+n);
    vector<LL>c;

    i=1,j=n;
    while(i<j){
        c.push_back(a[i]);
        c.push_back(a[j]);
        i++,j--;
    }
    if(n%2){
        c.push_back(a[(n+1)/2]);
    }
    LL sum3=0;
    for(int i=1;i<c.size();i++){
        sum3+=abs(c[i]-c[i-1]);
    }
    len=c.size()-1;
    LL sum4=abs(c[0]-c[len]);
   // cout<<sum<<endl;
    for(int i=1;i<len;i++){
        sum4+=abs(c[i]-c[i-1]);
    }
    LL num=max(sum3,sum4);
    LL num1=max(sum,sum1);
    printf("%lld\n",max(num,num1));
    return 0;
}
