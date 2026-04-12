#include<iostream>
#include<string>
using namespace std;
typedef struct{
  string first;
  int score,num;
} team;
int main(){
  int n,a,b,c,k=-1,nn[51];
  team t[51][11];
  cin >> n;
  while(n != 0){
    k++;
    nn[k] = n;
    for(int i=0;i<n;i++){
      cin >> t[k][i].first >> a >> b >> c;
      t[k][i].score = a*3+c;
      t[k][i].num = i;
    }
    for(int i=0;i<n-1;i++){
      for(int j=i+1;j<n;j++){
	if(t[k][i].score < t[k][j].score){
	  team temp = t[k][i];
	  t[k][i] = t[k][j];
	  t[k][j] = temp;
	} else if(t[k][i].score == t[k][j].score && t[k][i].num > t[k][j].num){
	  team temp = t[k][i];
	  t[k][i] = t[k][j];
	  t[k][j] = temp;
	}
      }
    }
    cin >> n;
  }
  for(int j=0;j<=k;j++){
    for(int i=0;i<nn[j];i++){
      cout << t[j][i].first << ',' << t[j][i].score << endl;
    }
    if(j != k) cout << endl;
  }
  return (0);
}