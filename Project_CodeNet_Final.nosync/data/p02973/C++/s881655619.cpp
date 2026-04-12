#include <bits/stdc++.h>
using namespace std;
int a[100020],n,x;
int f[100020];
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
    reverse(a,a+n);
    memset(f,0x3f,sizeof f);
    for(int i=0;i<n;i++){
        int p=upper_bound(f,f+n,a[i])-f;
        f[p]=a[i];
    }
    int ans2=lower_bound(f,f+n,0x3f3f3f3f)-f;
    cout<<ans2<<endl; 
}