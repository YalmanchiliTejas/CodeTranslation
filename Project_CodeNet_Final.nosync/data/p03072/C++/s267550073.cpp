#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int > pp;
typedef long long ll;
 
#define sz(x) (int)x.size() 
int const N=3e5+10,oo=1e9;
ll const OO=2e18;
double const eps=1e-8,PI=acos(-1);
int mod=oo+7;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,an=0,mx=0;
  cin>>n;
  for(int i=0;i<n;i++){
  	int a;
  	cin>>a;
  	if(a>=mx)an++;
  	mx=max(mx,a);
  }
  cout<<an<<'\n';
  return 0;
}




