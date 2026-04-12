#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF = 1001001001;

int a[12][12];

int main() {
 string S;
 cin>>S;
 for(int i=0;i<S.size()-1;i++){
   if(S.substr(i,2)=="AC"){cout<<"Yes"<<endl;return 0;}
 }
   cout<<"No"<<endl;
  return 0;
}