#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct data{
  int num;
  int score;
};
data da[1000];

int b_sort(int j){
  int tmp;
  tmp = da[j].score;
  da[j].score = da[j+1].score;
  da[j+1].score = tmp;

  tmp = da[j].num;
  da[j].num = da[j+1].num;
  da[j+1].num = tmp;
}

int main(){

  int n; 
  for(n = 0;;n++ ){
    scanf("%d,%d",&da[n].num,&da[n].score);
    if(da[n].num == 0 && da[n].score == 0 )break;
  }

  for(int i = n-1 ; i >= 0 ; i--){
    for(int j = 0 ; j < n ; j++ ){
      if(da[j].score < da[j+1].score){
	b_sort(j);
      }
    }
  }
  int table[1000],rank = 1;
 
  for(int i = 0; i < n; i++){
    table[da[i].num] = rank;
    if(da[i].score > da[i+1].score)rank++;
  }

  int call;
  while(cin >> call){
    cout << table[call] << endl;
  }

}