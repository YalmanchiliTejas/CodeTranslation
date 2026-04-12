#include<bits/stdc++.h>
using namespace std;

int main(){
   int n;
   cin >> n;
   int arr[n+5];
   int x = 0 , cnt = 0;
   for(int i = 1; i <= n; i++){
     cin >> arr[i];
     if(arr[i] >= x){
       x = arr[i];
       cnt++;
     }
   }
   cout << cnt << endl;
}