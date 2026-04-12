#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define rep(i,a) for(int i = 0 ; i < a ; i ++)
#define loop(i,a,b) for(int i = a ; i < b ; i ++)
#define vi vector<int>
#define vs vector<strinx>
#define pii pair<int, int>
#define f first
#define s second
#define pb push_back
using namespace std;

int main(void){
  int n;
  cin>>n;
  vi v(n),tmp;
  rep(i,n)cin>>v[i];
  tmp = v; 
  sort(tmp.begin(),tmp.end());
  rep(i,n){
    if(v[i] >= tmp[n/2])cout<<tmp[n/2-1]<<endl;
    else cout<<tmp[n/2]<<endl;
  }
}
