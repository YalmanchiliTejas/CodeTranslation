#include<iostream>
#include<iomanip>
#include<algorithm>
#include<bitset>
#include<cstdio>
#include<cmath>
#include<map>
#include<numeric>
#include<set>
#include<sstream>
#include<string>
#include<utility>
#include<vector>

#define rep(i, a, n)  for(int i=a; i<n; ++i)
#define per(i, a, n)  for(int i=n-1; i>=a; --i)
#define fill0(n)  setfill('0') << right << setw(n)
#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define INF 1000000007
using namespace std;
typedef long long ll;

int main(){
  int N;  cin >> N;
  string S; cin >> S;
  int K;  cin >> K;
  char c = S[K-1];
  for(char& sc:S){
    if(sc != c){
      sc = '*';
    }
  }
  cout << S << endl;
  return 0;
}