#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 

int main(){
    int n; cin>>n; 
    int b[n]; 
    int a[n]; for(int i=0;i<n;i++) { cin>>a[i]; b[i]=a[i]; }
    sort(a,a+n); 
    for(int i=0;i<n;i++){
        int l=0,h=n-1;
        int m;
        int pos; 
        while((h-l)>1){
            m=(l+h)>>1; 
            if(a[m]>b[i]) h=m-1;
            else if(a[m]<b[i]) l=m+1; 
            else break; 
        }
        if(a[m]==b[i]) pos=m; 
        else if(a[l]==b[i]) pos=l; 
        else pos=h; 
        if(pos<n/2) { cout<<a[n/2]<<endl; }
        else { cout<<a[n/2-1]<<endl; }
    }

	return 0; 
}

