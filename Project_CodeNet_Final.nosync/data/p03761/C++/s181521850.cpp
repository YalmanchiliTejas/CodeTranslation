#include <bits/stdc++.h>
using namespace std;
//#define int lint
typedef long long lint;
typedef pair<int,int> P;
const int    INF=(int)1e9;
const int    MOD=(int)1e9+7;
const double EPS=(double)1e-10;
struct Accelerate_Cin{
    Accelerate_Cin(){
        cin.tie(0); ios::sync_with_stdio(0);cout<<fixed<<setprecision(20);
    };
};



signed main(){
  int n;cin>>n;

  int  a[30]={0};
  for(int t=0;t<n;t++){
    string s;cin>>s;
    int b[30]={0};
    for(unsigned int i=0;i<s.size();i++){
      int temp=s[i]-'a';
      b[temp]++;
    }

    if(t==0)memcpy(a,b,sizeof(b));

    for(int t=0;t<26;t++)a[t]=min(a[t],b[t]);
  }

  for(char t='a';t<='z';t++){
    for(int i=0;i<a[t-'a'];i++){
      cout<<t;
    }
  }

  cout<<"\n";
  return 0;
}
