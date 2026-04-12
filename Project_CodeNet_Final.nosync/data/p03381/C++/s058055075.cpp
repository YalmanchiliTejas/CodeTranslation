#include<cstdio>
#include<iostream>
#include<map>
#include<algorithm>
#include<set>
#include<cstring>
using namespace std;
int main()
{
    int n,i,j,k,num[200005],num1[200005];
    cin>>n;
    for(i=1;i<=n;i++)scanf("%d",&num[i]);
    memcpy(num1,num,sizeof(num));sort(num+1,num+1+n);
    for(i=1;i<=n;i++){
        int pos=lower_bound(num+1,num+1+n,num1[i])-num;
        if(pos<=n/2)cout<<num[n/2+1]<<endl;
        else cout<<num[n/2]<<endl;
    }

    return 0;
}