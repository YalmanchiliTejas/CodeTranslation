#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#define ll long long
using namespace std;
int main(){
     int N;
     int count = 0;
     int flag = 1;
     vector<int> H;
     cin >> N;
     H.resize(N);
     for(int i = 0; i < N; i++){
          cin >> H[i];
          flag  = 1;
          for(int j = 0; j < i; j++){
               if(H[j] > H[i]){
                    flag = 0;
               }
          }
          if(flag == 1){
               count++;
          }
     }
     cout << count << endl;
     return 0;
}