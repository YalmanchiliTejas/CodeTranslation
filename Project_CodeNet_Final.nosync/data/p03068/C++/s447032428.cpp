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
#define MOD 1e9+7
int main(){
  //input
int n,k,i;cin>>n;vchar s(n);for(i=0;i<n;i++){cin>>s[i];}
  cin>>k;vint a(n,0);
  

  //caricurate
for(i=0;i<n;i++){if(s[i] ==s[k-1]){a[i]=1;}}
for(i=0;i<n;i++){if(a[i]){cout<<s[k-1];}else{cout<<"*";}}

  //output
cout<<endl;

}