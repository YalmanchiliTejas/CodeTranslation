#include <bits/stdc++.h>
using namespace std;
vector <string> v;
vector<int> ans;
string s ;
int main(){
  int N;
  cin >>N;
  while(N != 0){
    vector<int> num;
    for (int j = 0;j < N;j++){
      int x;
      cin >> x;
      num.push_back(x);
    }
    sort(num.begin(),num.end());
    int z;
    z = accumulate(num.begin()+1,num.end()-1,0);
    z = (int)z/(N-2);
    ans.push_back(z);
    cin >> N;
}

for (int i = 0 ; i < (int)ans.size();i++){
  cout <<ans[i]<<endl;
}

  return 0;
}

