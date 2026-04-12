#include<bits/stdc++.h>
using namespace std;
typedef long long int llint;
typedef long int lint;
typedef vector<char> vchar;
typedef vector<int> vint;
typedef vector<vector<int>> vvint;
typedef vector<vector<char>> vvchar;
#define vsort(v) sort((v).begin(), (v).end())
#define vreverse(v) reverse((v).begin(), (v).end())
#define pb(a) push_back(a)
#define INF 1000000007
int main(){
  int n,i;cin>>n;int ans=0;
  vint h(n);
  vint maxi(n);maxi[0]=0;//iまで（i含まず）最大
  for(i=0;i<n;i++){cin>>h[i];if(i){maxi[i]=max(maxi[i-1],h[i-1]);}}
  for(i=0;i<n;i++){if(h[i]>=maxi[i]){ans++;}}
  cout<<ans<<endl;
}
