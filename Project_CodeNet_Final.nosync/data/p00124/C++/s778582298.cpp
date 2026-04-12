#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

struct Team{
  string name;
  int win,lose,drow,score,zyun;
};

int main(){
  int i,j,n,max,k,c=0,z;
  Team t[11],tmp;
  while(1){
    cin >> n;
    if(n == 0) break;

    if(c != 0) cout << endl;
    c = 1;

    for(i=0;i<n;i++){
      cin >> t[i].name >> t[i].win >> t[i].lose >> t[i].drow;
      t[i].score = t[i].win * 3 + t[i].drow;
      t[i].zyun = i;
    }

    for(i=0;i<n;i++){
      max = t[i].score;
      for(j=i;j<n;j++){
	if(max < t[j].score) max = t[j].score;
      }
      z = n;
      for(j=i;j<n;j++){
	if(max == t[j].score && z > t[j].zyun){
	  z = t[j].zyun;
	  k = j;
	}
      }
      tmp = t[k];
      t[k] = t[i];
      t[i] = tmp;
    }

    for(i=0;i<n;i++) cout << t[i].name << "," << t[i].score << endl;

  }
  return 0;
}