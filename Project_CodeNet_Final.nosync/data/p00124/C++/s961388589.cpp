#include <iostream>
using namespace std;
struct po {
  string str;
  int score;
};

int main() {


int flg = 0;
  while(1) {
    
    int n;
    cin >> n;
    if(n == 0) break;

    po team[11];
    for(int i=0;i<n;i++) {
      int a,b,c;
      cin >> team[i].str >> a >> b >> c;
      team[i].score = a*3+c;
    }

    for(int i=0;i<n;i++) {
      for(int j=n-1;j>i;j--) {
	if(team[j].score > team[j-1].score) {
	  po t = team[j];
	  team[j] = team[j-1];
	  team[j-1] = t;
	}
      }
    }

    if(flg == 1) cout << endl;
    for(int i=0;i<n;i++) 
      cout << team[i].str<<","<<team[i].score<<endl;

    flg = 1;

  }

  return 0;
}