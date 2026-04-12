#include <bits/stdc++.h>

using namespace std;
const int N = 200005;
typedef long long ll;
int a[N];
int b[N];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
   }
   sort(a+1,a+1+n);
    int mid=n/2;
    for(int i=1;i<=n;i++){
        if(b[i]<=a[mid])
        printf("%d\n",a[mid+1]);
        else
        printf("%d\n",a[mid]);
    }
}
