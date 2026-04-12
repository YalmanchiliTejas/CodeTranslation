#include <bits/stdc++.h>
#define r(i,n) for(int i = 0; i<n; i++)
typedef long long ll;
using namespace std;

int main(){
  int h,w,count=0;
  cin >> h >> w;
  char a;
  r(i,h*w){
    cin >> a;
    if(a=='#')count++;
  }
  if(count==h+w-1)cout << "Possible"<<endl;
  else cout << "Impossible"<<endl;
}