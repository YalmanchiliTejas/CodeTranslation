#include <bits/stdc++.h>
using namespace std;

int main(void){

   int N,ans = 1;
   cin >> N;
   int data[N];
   
   for(int i=0;i<N;i++) cin >> data[i];

   for(int i=1;i<N;i++){
       int sum = 0;
       for(int j=0;j<i;j++){
           if(data[j] <= data[i]) sum++;
           else break;
       }
       
       if(sum == i) ans++;
   }
   
   cout << ans << endl;
}