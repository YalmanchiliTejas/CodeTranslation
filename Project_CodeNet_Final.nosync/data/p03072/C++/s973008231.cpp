 #include<bits/stdc++.h>
 using namespace std;
int main(){
  int N;
  cin >> N;
  int H[30];
  for (int i = 0; i < N; i++) {
    cin >> H[i];
  }
  int res = 1;
  int max = H[0];
  for (int i = 1; i < N; i++) {
    if (H[i] >= max) {
      res++;
      max = H[i];
    }
  }

  cout << res << "\n";
}
