#include<iostream>
#include<cstdio>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

int main(){
  pair<int,char> shop[5];
  int am[5],pm[5];

  while(1){
    cin >> am[0] >> pm[0];
    if(am[0] == 0 && pm[0] == 0)break;

    for(int i=1;i<5;i++){
      cin >> am[i] >> pm[i];
    }
    
    for(int i=0;i<5;i++){
      shop[i].first = am[i] + pm[i];
      shop[i].second = 'A' + i;
    }
  
    sort(shop,shop+5);

    cout << shop[4].second << ' ' << shop[4].first << endl;
  }
  return 0;
}