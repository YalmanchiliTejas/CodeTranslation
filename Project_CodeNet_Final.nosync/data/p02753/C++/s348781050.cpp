#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef double dd;
const int N = 1e5+5;
const dd eps = 1e-8;
const int mod = 1e9+7;

int cnt1,cnt2;
string now;


int main(){
  ios::sync_with_stdio(false);
  // freopen("input.txt","r",stdin);
  cin>>now;
  for(int i = 0;i < now.size();i++){
    if(now[i] == 'A') cnt1++;
    if(now[i] == 'B') cnt2++;    
  }
  if(cnt1 && cnt2) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;  
  return 0;
}
