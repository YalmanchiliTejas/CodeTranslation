#include <bits/stdc++.h>
#include<queue>
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef pair<double,double> Pdouble;

const int INF = 2000000000;
const int MOD = 1000000007;

int main(){
  string s;
  cin >> s;
  char c = s.at(0);
  bool flag = false;
  for(int i=0; i<3; i++){
    if(c != s.at(i)){
      flag = true;
    }
  }

  if(flag){
    cout << "Yes" << endl;
  }else{
    cout << "No"<< endl;
  }
}
