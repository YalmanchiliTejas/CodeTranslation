#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define rep(i,a) for(int i = 0 ; i < a ; i ++)
#define loop(i,a,b) for(int i = a ; i < b ; i ++)
#define vi vector<int>
#define vs vector<string>
#define pii pair<int, int>
#define f first
#define s second
#define pb push_back
using namespace std;

int main(void){
  int x,y,z;
  cin>>x>>y>>z;

  x -= z;
  cout<<(x/(y+z))<<endl;
}