#include<iostream>
#include<vector>

using namespace std;
vector<int> data;
int main(void){
  int n;
  cin >> n;
  data = vector<int>(n);
  for(int i=0;i<n;i++){
    cin >> data[i];
  }
  int ans = 1;

  for(int i=1;i<n;i++){
    bool flag = false;
    for(int j=0;j<i;j++){
      if(data[j] <= data[i]){
        flag = true;
      }else{
        flag = false;
        break;
      }
    }
    if(flag){
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
