#include<iostream>
#include<algorithm>
using namespace std;

int main(){

  int n,m;
  int a;
  int data[20001];

  while(true){
    cin >> n >> m;
    if(!n && !m) break;

    for(int i=0;i<n;i++){
      cin >> a;
      data[i] = a;
    }

    for(int i=n;i<n+m;i++){
      cin >> a;
      data[i] = a;
    }

    sort(data, data+n+m);

    int ans = data[0];
    for(int i=1;i<n+m;i++) ans = max(ans,data[i]-data[i-1]);

    cout << ans << endl;
  }

}