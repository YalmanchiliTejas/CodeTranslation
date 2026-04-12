#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int a,b;
int main(){
  int n;
  cin >> n;
  string s;int ans[30];
  for(int i=0;i<30;i++) ans[i]=1e8;
  for(int i=0;i<n;i++){
    cin >> s;
    int c[30]={0};
    for(int j=0;j<s.size();j++){
            c[s[j]-'a']++;
    }
    for(int j=0;j<26;j++){
      ans[j]=min(ans[j],c[j]);
    }
  }
  char ch='a';
for(int i=0;i<26;i++){
  for(int j=0;j<ans[i];j++){
    cout << ch;
  }
  ch++;
}
cout <<endl;
  }
