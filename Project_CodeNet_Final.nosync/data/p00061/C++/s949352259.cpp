#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct rank{
  int num, ans, ranking;
}Rank;

typedef struct data{
  int score, ranking;
}Data;

int main(){
  int n,a,i=0;
  Rank r[100];
  while(scanf("%d,%d", &n, &a) != EOF){
    if( n==0 && a==0 ) break;
    r[i].num = n;
    r[i].ans = a;
    i++;
  }

  int count=1;
  vector<int> score;
  Data d[100];
  
  
  for(int j=0; j<i; j++)  score.push_back(r[j].ans);
  
  sort(score.begin(), score.end(),greater<int>() );
  int max=score[0];

  for(int j=0; j<i; j++){
    if(max == score[j]) continue;
    else{
      d[count-1].score = max;
      d[count-1].ranking = count;      
      max = score[j];
      count++;
    }
  }

  d[count-1].score = max;
  d[count-1].ranking = count;
  
  for(int j=0; j<count; j++){
    for(int k=0; k<i; k++){
      if(d[j].score == r[k].ans) r[k].ranking = d[j].ranking;
    }
  }
    
  int cheak;

  while(cin >> cheak){
    cout << r[cheak-1].ranking << endl;
  }
}