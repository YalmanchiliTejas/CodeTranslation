#include <bits/stdc++.h>
#define r(i,n) for(long long i = 0; i<n; i++)
typedef long long ll;
using namespace std;

int main() {
  int a[26]={0};
  int n;
  cin >> n;
  r(i,n){
    string s;
    cin >> s;
    unordered_map<int,int> m;
    r(j,s.size()){
      m[s[j]-'a']++;
    }
   if(i){
     r(j,26){
      a[j]=min(m[j],a[j]);
    }
   }
    else  r(j,26)a[j]=m[j];
  }
  int i = 0;
  while(i<26){
    while(a[i]>0){
      cout<<char('a'+i);
      a[i]--;
    }
    i++;
  }
  cout<<endl<<endl;
}