#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
#define reps(i,j,n) for(int i = j ; i < n ; ++i)
#define rep(i, n) reps(i,0,n)
#define fr first
#define sc second
#define SQR(x) ((x)*(x))
#define INF (1 << 28)
typedef pair< int , int > Pt;

int main(){
  int n,c;
  while(cin >> n , n){
    vector<Pt> mas;
    rep(i,n){
      cin >> c;
      int back = mas.size() - 1;
      if( i % 2 == 0 ){
        if( mas.empty() || c != mas[back].first ){
          mas.push_back(Pt(c,1));
        }else mas[back].second++;
      } else {
        if( c != mas[back].first ){
          int rec = 1 + mas[back].second;
          mas.pop_back();
          back--;
          if( mas.empty() ) mas.push_back(Pt(c,rec));
          else mas[back].second += rec;
        } else mas[back].second++;
      }
    }
    int rec = 0;
    rep(i,mas.size()) if(mas[i].first == 0) rec += mas[i].second;
    cout << rec << endl;
  }
}