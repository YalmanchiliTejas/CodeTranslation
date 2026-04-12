#include <bits/stdc++.h>
using namespace std;
int main(){
    
     int n=0,x=0,y=0,ans=0;
     scanf("%d",&n);
       if(n>=15){
	 x=n*800;
     y=((n/15)*200);
     ans=x-y;
     printf("%d",ans);
       }
	   else{
	   x=n*800;
       ans=x;
       printf("%d",ans);
	}


}