#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int a[n];
  int b=0,l=0;
  for(int i=0;i<n;i++){
	cin >> a[i];
    if(b<=a[i]){
	  l++;
      b=a[i];
    }
  }
  cout << l;
}