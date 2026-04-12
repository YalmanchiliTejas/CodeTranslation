#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
  int n,m,max,i,x;
  vector<int>time;

  while(cin >> n >> m){
    time.push_back(0);
    if(n==0 && m==0)break;
    for(i=0;i<n+m;i++){
      cin >> x;
      time.push_back(x);
    }
    sort(time.begin(),time.end());
    max=-1;
    for(i=0;i<n+m;i++){
      max= (max<time[i+1]-time[i])?time[i+1]-time[i]:max;
}
    cout << max << endl;
    time.clear();
  }

  return 0;
}