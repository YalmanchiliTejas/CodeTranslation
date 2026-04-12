#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  char C;
  cin>>C;
  string ans="consonant";
  if(C=='a'||C=='e'||C=='i'||C=='u'||C=='o')ans="vowel";
  cout<<ans<<endl;
}