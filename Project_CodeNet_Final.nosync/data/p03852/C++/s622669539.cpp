//g++ test1.cc　でコンパイル
//./a.out <input.txt
#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;
typedef long long ll;
using Graph =vector<int>;
typedef pair<ll,int> P;

const ll MAX_N=131072;
int bit[MAX_N*2-1];
ll n;
int main(){
  string s;
  cin >>s;
  if(s=="a"||s=="e"||s=="i"||s=="o"||s=="u") cout <<"vowel"<<endl;
  else cout <<"consonant"<<endl;
}
