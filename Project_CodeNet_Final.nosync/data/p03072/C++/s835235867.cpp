#include <bits/stdc++.h>
using namespace std;

int mae_max (vector<int> &c ,int i){
int kaeshi_max = c.at(0);
  
  if (i == 0){
   return  c.at(0);
  }
    
kaeshi_max = max(mae_max (c ,i - 1),c.at(i - 1) );    
return kaeshi_max;
}
  

int main (){
int N;
cin >> N;
vector<int> vec(N);
for (int i = 0; i < N; i++){
   cin >> vec.at(i);
  }
int count = 0;
for (int i = 0; i < N; i++){
   if(mae_max (vec , i) <= vec.at(i) )
    count++;
  }
cout << count << endl;
  
}