#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans,a[55],b[55];
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    a[0]=b[0]=1;
    for(int i=1;i<=n;i++)
    	a[i]=a[i-1]*2+3,b[i]=b[i-1]*2+1;
    for(int i=n;i>=0;i--){
    	if(m<=0)break;
    	if(m==a[i]){ans+=b[i];break;}
    	if(m==1)break;
    	if(m<=a[i-1]+1)m--;
    	else ans+=b[i-1]+1,m-=a[i-1]+2;
	}
    cout << ans;
    return 0;
}