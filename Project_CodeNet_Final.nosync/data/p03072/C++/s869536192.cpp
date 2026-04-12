#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

#define inf 10000000000 + 5

int n;
int h[22];
int answer = 0;
int tmp[22];

int main(){
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> h[i];
  }
  //cout << n;
  for(int i = 0; i < n; ++i){
    tmp[i] = 0;
    for(int j = 0; j < i; ++j){
      if(h[i] >= h[j]){
        //return 0;
        tmp[i]++;
      }
    }
    //cout << tmp[i] << endl;
    if(tmp[i] == i){
      answer++;
    }
  }
  cout << answer << endl;
}