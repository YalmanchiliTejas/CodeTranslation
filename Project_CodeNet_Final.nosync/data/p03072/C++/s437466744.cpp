  #include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
    cin >> n;
  int H[n];
  for(int i = 0; i < n; i++){
    cin >> H[i];
  }
int mx = 0 , ans = 0;
for(int i = 0; i < n; i++){
  if(H[i] >= mx){
    ans++;
    mx = H[i];
  }
}
  cout << ans;
}
