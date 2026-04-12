#include<bits/stdc++.h>

using namespace std;

int main(){
 int N;
 cin >> N;
 vector<int> H(N);

 for(int i = 0; i < N; i++) cin >> H[i];
 
 int sum = 1;
 int hantei = 1;
 for(int i = 1; i < N; i++){
   hantei = 1;
   for(int j = 0; j <= i - 1; j++){
     if(H[i] < H[j]){ hantei = 0; break; }
   }
   if(hantei == 1){ sum += 1;}
 }

 cout << sum << endl;
  return 0;
}

