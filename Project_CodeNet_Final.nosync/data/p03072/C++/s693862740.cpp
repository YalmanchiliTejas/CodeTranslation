#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i< (n); i++)
using namespace std;

int main() {
 int n;
 cin >> n;
 vector<int> h(n);
 rep(i,n) cin >> h[i];
 int count = 1;
 int height = h[0];
 for(int i = 1; i<n; i++){
   if(height <= h[i]){
     count++;
   }
   height = max(height, h[i]);
 }
cout << count << endl;
}