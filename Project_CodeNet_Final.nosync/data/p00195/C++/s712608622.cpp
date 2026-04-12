#include <iostream>
using namespace std;
int main(void){
   int s1[5], s2[5];

   while(true){
       for(int i = 0; i < 5; i++){
           cin >> s1[i] >> s2[i];
           if(s1[0] == 0 && s2[0] == 0) return 0;
       }

       int sum[5];
       int max = 0; 
       char n[5] = {'A', 'B', 'C', 'D', 'E'};
       int p;

       for(int i = 0; i < 5; i++){
           sum[i] = s1[i] + s2[i];
           if(sum[i] > max){
               max = sum[i];
               p = i;
           }
       }
       cout << n[p] << " " << max << endl;
   }
}
