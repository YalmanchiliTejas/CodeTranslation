#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int n;
lli arr[50];

int main() {
    lli k=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%lld",arr+i);

    bool f=true;
    while(f) {
        f=false;
        
        lli c=0;
        for(int i=0;i<n;i++) if(arr[i]>=n) {
            f=true;
            c+=arr[i]/n;
        }
        for(int i=0;i<n;i++) arr[i]+=(c-arr[i]/n)-(arr[i]/n*n);
        k+=c;
    }
    printf("%lld\n",k);

    return 0;
}
