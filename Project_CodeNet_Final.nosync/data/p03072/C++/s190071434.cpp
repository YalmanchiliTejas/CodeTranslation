#include <bits/stdc++.h>
using namespace std;

int main(){
   int n;
   cin >> n;
   int max = 0;int sum = 0;
   for(int i =0;i<n;i++){
     int a;
     cin >> a;
     if(a >= max){
       max = a;
        sum += 1;
     }
   }
   cout << sum << endl;
}