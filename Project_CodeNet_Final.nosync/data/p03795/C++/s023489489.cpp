#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#define lli long long int
#define uli unsigned long long int
#define inf 999999999999999999
#define rep(i,m,n) for(lli i = m;i < n;i++)
#define per(i,m,n) for(lli i=m-1;i>=n;i--)
#define st(n) sort(n.begin(), n.end())
#define rev(n) reverse(n.begin(),n.end())
#define ou(S) cout << S << endl
using namespace std;
int main(){
  int n;
  cin>>n;
  cout<<n*800-(n/15)*200<<endl;
}