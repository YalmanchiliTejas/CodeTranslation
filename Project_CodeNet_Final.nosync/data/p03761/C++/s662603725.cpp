#include <bits/stdc++.h>
using namespace std;
 
#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
 
#define ll long long
 
#define pq(name,type) priority_queue<type> name
#define vec(name,type,length,value) vector<type> name(length,value)
#define vec2(name,type,length,width,value) vector<vector<type>> name(length,vector<type>(width,value));
 
int main(){
	int N;
  cin >> N;
  vector<int> a(26,0);
  string s;
  cin >> s;
  int l = s.length();
  froop1(0,l){
   int b = s[i] - 'a';
    a.at(b)++;
  }
  
  froop1(1,N){
    cin >> s;
    int l = s.length();
    vector<int> a2(26,0);
   for(int j = 0;j < l;j++){
     int b = s[j] - 'a';
     a2.at(b)++;
   }
    for(int j = 0;j < 26;j++){
      a.at(j) = min(a.at(j),a2.at(j));
    }
  }
  string ans = "";
  froop1(0,26){
   for(int j = 0;j < a.at(i);j++){
     ans += 'a' + i;
   }
  }
  cout << ans << endl;
 
  return 0;
}