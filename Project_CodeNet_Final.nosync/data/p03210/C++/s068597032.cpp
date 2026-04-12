#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <set>
#define INF 1000000000
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define LOOP(i,N) for(int i=0;i<N;i++)
#define LOOP1(i,N) for(int i=1;i<=N;i++)
typedef pair<int,int> P;
typedef pair<int,pair<int,int> > PP;

#define MAN 200000

int main(){
  int x;
  cin >> x;
  if(x==3 || x==5 || x==7){
    cout << "YES";
  }else{
    cout << "NO";
  }
}
