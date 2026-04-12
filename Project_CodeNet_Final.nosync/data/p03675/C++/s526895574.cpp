#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> s,t;

int main() {
  cin >> n;
 
  for(int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if(i % 2 == 0) s.push_back(a);
    else t.push_back(a);
  }
  reverse(t.begin(),t.end());

   if(n % 2 == 1) {
    reverse(t.begin(),t.end());
    reverse(s.begin(),s.end());
     for(int i = 0; i < s.size(); i++) {
    cout << s[i] <<' ';
  }

     for(int i = 0; i < t.size(); i++) {
       cout << t[i] <<" ";
     }
     cout << endl;
     return 0;
     }
  
  for(int i = 0; i < t.size(); i++) {
    cout << t[i] <<' ';
  }
  
  for(int i = 0; i < s.size(); i++) {
    cout << s[i] <<" ";
  }
  cout << endl;
}

  

  
    
  
