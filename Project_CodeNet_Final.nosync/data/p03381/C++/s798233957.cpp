#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
#include<set>
#include<complex>
#define INF 2147483647
#define llINF 9223372036854775807
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long

using namespace std;
int main(){
  int n;cin>>n;
  vector<ll >x(n),x2(n);
  for(int i=0;i<n;i++){cin>>x[i];x2[i]=x[i];}
  sort(x.begin(),x.end()); 
  for(int i=0;i<n;i++){
    if(x2[i]<x[n/2-1])
      cout<<x[n/2]<<endl;
    else if(x2[i]==x[n/2-1])
      cout<<x[n/2]<<endl;
    else
      cout<<x[n/2-1]<<endl;
  }
  return 0;
}
