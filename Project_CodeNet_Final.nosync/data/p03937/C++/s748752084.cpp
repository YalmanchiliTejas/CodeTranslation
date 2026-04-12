#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX_N = 30;    // Change as necessary
const ll  MODD = 1000000009; //

char A[MAX_N][MAX_N];
int H,W;

int ctr;

void f(int I,int J){
  if(A[I][J] != '#') return;
  
  if(A[I+1][J] == '#' && A[I][J+1] == '#'){
    cout << "Impossible" << endl;
    exit(0);
  }
  
  if((I && A[I-1][J] == '#') || (J && A[I][J-1] == '#')){
    cout << "Impossible" << endl;
    exit(0);
  }
  
  if(I == H-1 && J == W-1){
    ctr++;
    return;
  }
  
  A[I][J] = 'w';
  
  f(I+1,J);
  f(I,J+1);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> H >> W;
  for(int i=0;i<H;i++)
    for(int j=0;j<W;j++)
      cin >> A[i][j];
  
  f(0,0);
  
  cout << (ctr == 1 ? "Possible" : "Impossible") << endl;
  
  return 0;
}
