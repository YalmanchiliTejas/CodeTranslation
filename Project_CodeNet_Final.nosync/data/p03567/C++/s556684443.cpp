#include<bits/stdc++.h>
using namespace std;
char a[10],l;
int main(){
gets(a);
l=strlen(a);
for(int i=0;i<l-1;i++){
if(a[i]=='A'&&a[i+1]=='C'){
printf("Yes");
return 0;
}
}
printf("No");
return 0;}