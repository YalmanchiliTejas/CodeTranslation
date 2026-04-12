#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(),(a).end())
#define YN(a) if(a){cout<<"Yes"<<endl;}else cout<<"No"<<endl;//条件によってYes、Noを出力する
#define ld long double
int main(){
  int n;
  cin>>n;
  string s;
  cin>>s;
  int k;
  cin>>k;
  rep(i,n){
    if(s[i]!=s[k-1]){
      cout<<"*";
    }
    else{
      cout<<s[i];
  }
  }
   cout<<endl;
}
