#include<iostream>
#include<cmath>
using namespace std;
typedef long long int ll;

const int MAX_N = 51;

int main(){
  ll N,X;
  cin >> N >> X;

  ll len[MAX_N];
  ll cntp[MAX_N];
  len[0] = 1;
  cntp[0] = 1;
  for(int i = 1 ; i < MAX_N ; i++){
    len[i] = len[i-1]*2 + 3;
    cntp[i] = cntp[i-1]*2 + 1;
  }
  ll sum = 0;
  while(X > 0 && N >= 0){
    //cout << "X = " << X << " N = " << N << " sum = " << sum << endl;
    if(N == 0){
      sum++;
      break;
    }
    ll c = (ll)ceil((double)len[N]/2);
    //cout << "c = " << c << endl;
    if(X >= c){
      sum += (cntp[N-1] + 1); // P
      //cout << "(cntp[N-1] + 1) = " << (cntp[N-1] + 1) << endl;
      N--;
      X -= (len[N] + 2); // P,B
      //cout << "(len[N-1] + 2) = " << (len[N-1] + 2) << endl;
    }
    else{
      N--;
      X--;
    }
    //cout << "===" << endl;
  }
  cout << sum << endl;
  return 0;
}
