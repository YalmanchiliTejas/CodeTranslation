#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define vi vector<int>
typedef long long ll;

int main(){
  string S;cin >> S;
  if((S[0] == S[1]) &&(S[1] == S[2]))
    cout << "No";
  else
    cout << "Yes";
}
