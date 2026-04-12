#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  int n;
  cin >> n;
  int cnt = 1;
  int m;
  cin >> m;
  for(int i=1; i<n; i++){
    int tmp;
    cin >> tmp;
    if(m<=tmp){
      cnt++;
      m = tmp;
    }
  }
  cout << cnt << endl;
  return 0;
}
