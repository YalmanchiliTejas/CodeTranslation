#include<bits/stdc++.h>
using namespace std;


int main() {
  int n;
  cin >> n;
 int a[n];
  int max = -1;
  int count = 0;
  for(int i = 0;i < n;i++){
    cin >> a[i];
    //cout <<i <<endl;
   if(a[i] >= max){
   max = a[i];
   count++;
  
    }
  }

cout << count << endl;
}