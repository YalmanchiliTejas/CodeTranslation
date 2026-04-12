#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n,num,cnt,max;
  vector<int> h;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> num;
    h.push_back(num);
  }
  cnt=1;
  max=h[0];
  for(int i=1;i<n;i++){
    if(max<=h[i]){
      max=h[i];
      cnt++;
    }
  }
  cout << cnt << endl;
}
