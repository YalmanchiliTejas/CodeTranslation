#include <bits/stdc++.h>

using namespace std;

int main(void){
//string S;
int N;
cin >> N;
int M;
cin >> M;
/*long long mincost = 0;
//vector<int> H(N);

for(int i = 0; i < N; i++){
  cin >> H[i];
}

sort(H.begin(), H.end(), greater<int>());

for(int i = K; i < H.size(); i++){
  mincost += H[i];
}*/
if(M == N) cout << "Yes" << endl;
if(M < N) cout << "No" << endl;

return 0;
}
