#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
#define REP(i,a,b) for(int i=a;i<(b);++i)
using namespace std;
typedef long long ll;

int a[8][8];

int h,w;
int check(int i, int j){
  int ret=0;
  // cout << "i,j"<<i <<","<<j<<endl;
  if(i==h-1 && j==w-1)
    return 1;
  if(i < h-1 && a[i+1][j])
    ret += check(i+1,j);
  if(j < w-1 && a[i][j+1])
    ret += check(i,j+1);
  return ret;
}

int main()
{
  int cnt=0;
  cin >> h >> w;

  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      char ch;
      cin >> ch;
      if(ch == '#'){
	a[i][j]=1;
	cnt++;
      }
      else
	a[i][j]=0;
      //cout << a[i][j];
    }
    cout <<endl;
  }
  if(cnt!= h+w-1){
    cout <<"Impossible"<<endl;
    return 0;
  }
  if(check(0,0))
    cout << "Possible"<<endl;
  else
    cout <<"Impossible"<<endl;
}
