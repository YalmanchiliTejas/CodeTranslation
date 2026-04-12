#include<bits/stdc++.h>
using namespace std;
long long a,b,k;
int main(){
    scanf("%lld%lld%lld",&k,&a,&b);
    if(k<=a)cout<<"1"<<endl;
    else if(a<=b)cout<<"-1"<<endl;
    else printf("%lld\n",((k-a)/(a-b)+bool((k-a)%(a-b)))<<1|1);
}