 #include <bits/stdc++.h>
using namespace std;


int main(){
  int N;
  cin >> N;
  vector<int>H(N);
  for(int i=0;i<N;i++){
    cin >> H[i];
  }
  int ans = 0;
  int H2 = 0;
  for(int i=0;i<N;i++){
    if(H[i]>=H2){
      ans++;
      H2=H[i];
    }
  }
  cout << ans << endl;
}
      
