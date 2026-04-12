#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const int MAX=200005;
const ll MOD=1000000007;
int a[MAX],b[MAX],n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]),b[i]=a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(b[i]>=a[n/2]) printf("%d\n",a[n/2-1]);
        else printf("%d\n",a[n/2]);
    }
}
