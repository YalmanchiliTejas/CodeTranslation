#include "bits/stdc++.h"
using namespace std;

int main(){
 int n;
 cin >>n;
 vector<int>a(n);
 for(int i=0;i<n;i++){
     cin >>a.at(i);
 }
 int ans =1;
 int che =a.at(0);
 for(int i=1;i<n;i++){ 
    if(che<=a.at(i)&&a.at(i-1)<=a.at(i)){
        ans++;
        che = max(che,a.at(i));
    }
 }
 cout << ans << endl;
}