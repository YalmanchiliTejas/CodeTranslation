#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int h[n];
    for(int i=0;i<n;i++) cin>>h[i];
    int cnt=0;
    for(int i=1;i<n;i++) {
        for(int j=0;j<i;j++) {
          	if(h[i]<h[j])break;
            if(j==i-1) cnt++;
        }
    }
    cout<<cnt+1<<endl;
}
