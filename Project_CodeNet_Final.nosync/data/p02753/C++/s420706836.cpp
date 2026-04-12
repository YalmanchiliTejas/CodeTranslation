
 
#include<bits/stdc++.h>
using namespace std;
int main(){
  
  string S;
  int ans =0;
  cin >> S;
  
  if(S == "AAA"){
    ans ++;
  }else if(S == "BBB"){
    ans ++;
  }
  if(ans == 0){
    cout << "Yes"<<endl;
  }else if(ans > 0){
    cout <<"No" <<endl;
  }
}
