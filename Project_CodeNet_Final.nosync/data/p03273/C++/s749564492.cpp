#include <functional>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
template
<   
    typename TYPE,
    std::size_t SIZE
>
std::size_t array_length(const TYPE (&)[SIZE])
{   
    return SIZE;
}

int main() {
    int N,W;
  
    vector<string> vec;  // 座標を受け取る配列
    cin >> N >> W;
    
    vec.resize(N); for (int i = 0; i < N; ++i) cin >> vec[i];
  
 int a[N];
 int b[W];
  
for(int i = 0;i<N;i++){
  int ans = 0;
  
  for(int j = 0;j<W;j++){
   
    if(vec[i][j]=='.'){
       
      ans++;
    }
    
  }
   
  if(W == ans){
   a[i] = 9999;
  }
   
}
  
  int bnum = 0;
  
  for(int i = 0;i<W;i++){
  int ans = 0;
    
   for(int j = 0;j<N;j++){
    if(vec[j][i]=='.'){
       
      ans++;
    }
        
     }
    if(N == ans){
   b[i] = 9999;
      bnum++;
  }
   //if(vec[0][i]==vec[1][i]&&vec[1][i]==vec[2][i]&&vec[2][i]==vec[3][i]){
  
   //   b[i] = 100;
  //    bnum++;
  // }

   
}
  
 
  for(int i = 0;i<N;i++){
    
    if(a[i]==9999){
    
      continue;
    }
    
    for(int j = 0;j<W;j++){
      
      if(b[j]==9999){
    
      continue;
     }
      
     
        cout << vec[i][j];
      
    }
    
     
       
        cout << endl;
      
  }
   
  
  return 0;
}