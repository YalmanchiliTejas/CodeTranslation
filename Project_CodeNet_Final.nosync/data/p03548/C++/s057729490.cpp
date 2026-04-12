#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#define INF 2147483647
#define llINF 9223372036854775807
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long

using namespace std;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  a=a-c;
  int ans=0;
  while(a>=b+c){
    a=a-b;
    a=a-c;
    ans++;
  }
  cout<<ans<<endl;
  return 0;
}
