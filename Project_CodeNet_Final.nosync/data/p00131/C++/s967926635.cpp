#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define fr first
#define sc second
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<int,pii> pip; 
const int INF = (1<<25);
const int dx[]={0,0,0,1,-1},dy[]={-1,1,0,0,0};

int d[11][11], b[11][11], a[11][11];

void flip(int x, int y) {
  a[y][x]=1;
  for(int i=0; i<5; i++) {
    b[y+dy[i]][x+dx[i]] = 1-b[y+dy[i]][x+dx[i]];
  }
}

int main() {

  int n;
  cin>> n;
  while(n--) {
    for(int i=0; i<10; i++) {
      for(int j=0; j<10; j++) {
	cin>> d[i][j];
      }
    }

    for(int i=0; i<1024; i++) {
      memset(a, 0, sizeof(a));
      memcpy(b, d, sizeof(d));
      for(int j=0; j<10; j++) {
	if((i>>j) & 1) flip(j, 0);
      }

      for(int j=1; j<10; j++) {
	for(int k=0; k<10; k++) {
	  if(b[j-1][k]) flip(k, j);
	}
      }

      int cnt=0;
      for(int j=0; j<10; j++) {
	if(b[9][j]) {
	  cnt=1; break;
	}
      }
      
      if(cnt==0) break;
    }

    for(int i=0; i<10; i++) {
      for(int j=0; j<10; j++) {
	cout << a[i][j]<< (j==9 ? "" : " ");
      }
      cout<< endl;
    }
  }
}