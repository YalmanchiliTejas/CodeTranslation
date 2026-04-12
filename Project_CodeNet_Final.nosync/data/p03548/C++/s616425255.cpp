#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0; i<N; i++)
#define lint long long
#define square_vector(name,N,M) vector<vector<lint>>name(N,vector<lint>(M,0))
#define sort(V) sort(V.begin(),V.end())

int main() {
  lint X,Y,Z;
  cin >> X >> Y >> Z;
  X -= Z;
  cout << X/(Y+Z) << endl;
}