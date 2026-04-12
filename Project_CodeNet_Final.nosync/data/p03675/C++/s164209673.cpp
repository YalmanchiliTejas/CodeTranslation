#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int MAX=200005;
const int INF=0x3f3f3f3f;
int n,a[MAX];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=n-1;i>=0;i-=2) printf("%d ",a[i]);
    for(int i=n%2;i<n;i+=2) printf("%d ",a[i]);
    return 0;
}
