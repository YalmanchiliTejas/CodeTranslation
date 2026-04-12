#include<bits/stdc++.h>
using namespace std;

int a[200005],b[200005];

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(a,a+n);
    int k=n/2;;
    for(int i=0;i<n;i++){
        if(a[k]>b[i]) printf("%d\n",a[k]);
        else printf("%d\n",a[k-1]);
    }
    return 0;
}
