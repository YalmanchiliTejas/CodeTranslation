#include <bits/stdc++.h>
using namespace std;

int main(){
   char A[4];
   cin>>A;
   int k=0;
   for(int i=0;i<3;i++){
       if(A[i]=='A')k++;
   }
   if(k==0||k==3)printf("No\n");
   else printf("Yes\n");
}
