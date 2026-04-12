#include <bits/stdc++.h>
#include <cmath>
#include <map>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INF = 1e18;
#define foreach(ix,a) for(auto& (ix) : (a) 
int main(){
  string n;
  cin>>n;
  if(n.at(0)!=n.at(1)||n.at(1)!=n.at(2))cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}