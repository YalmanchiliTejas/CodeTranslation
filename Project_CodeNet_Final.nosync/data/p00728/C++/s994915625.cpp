#include <cstdio>
int n;
int main(){
while(1){
scanf("%d",&n);
if(!n) break;
int sum=0,mini=1000000,maxi=0;
for(int i=0;i<n;i++){
int g;
scanf("%d",&g);
sum+=g;
mini=mini>g?g:mini;
maxi=maxi<g?g:maxi;
}
printf("%d\n",(sum-maxi-mini)/(n-2));
}
return 0;
}