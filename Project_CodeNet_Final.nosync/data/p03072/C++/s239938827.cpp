#include<iostream>
using namespace std;

int main(){
 int N; cin >> N;
 int H[N];
 int res = 0;

 for(int i=0; i<N; i++) cin >> H[i];
 
 for(int i=N-1; i>=0; i--){
   int flag = 1;
   for(int j=i-1; j>=0; j--){
   	int tmp = H[j] - H[i];
    if(tmp>0) flag = 0;
   }
   if(flag) res++;
 }
  cout << res << endl;
  return 0;
}