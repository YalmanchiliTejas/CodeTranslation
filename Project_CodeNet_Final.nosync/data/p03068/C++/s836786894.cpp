#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
  int N;
  cin >> N;
  char s[N];
for(int i=0;i<N;i++){
cin >> s[i];
}
int K;
cin >> K;
char r=s[K-1];
for(int i=0;i<N;i++){
if(s[i]!=r)
s[i]='*';
}
  for(int i=0;i<N;i++){
cout << s[i];
}
  return 0;
}
