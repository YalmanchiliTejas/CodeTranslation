#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[55],i,j,max=0,count=0;
    bool c=true;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    max=a[0];
    for(j=0;j<n;j++){
c=true;
for(int k=0;k<j;k++){

        if(a[k]>a[j]){
                c=false;break;
        }
      //  if(c!=false&&j!=0&&a[j]==max){count++;}

    }
    if(c){count++;}
    }
    cout<<count<<endl;
}