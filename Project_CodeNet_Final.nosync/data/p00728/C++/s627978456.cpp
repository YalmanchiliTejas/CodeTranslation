#include<bits/stdc++.h>
using namespace std;
int main(){
  while(1){
    int n;
    cin >> n;
    if(n==0)return 0;
    vector<int> a(n);
    for(int i=0;i<a.size();i++){
      cin >> a[i];
    }
    sort(a.begin(),a.end());
    int sum =0;
    for(int i=1;i<(a.size()-1);i++){
        sum+=a[i];
      }
    int avg = sum/(n-2);
    cout << avg << endl;
  }
}

