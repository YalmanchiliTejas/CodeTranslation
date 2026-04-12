#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef long long int ll;
typedef vector<pair<ll,ll> > Q;
typedef pair<int,int> P;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main()
{
  int n,k;
  string s;
  cin>>n>>s>>k;

  rep(i,n)
  {
    if(s.at(k-1)!=s.at(i)) cout<<'*';
    else cout<<s.at(i);
  }
  cout<<endl;
  return 0;
}