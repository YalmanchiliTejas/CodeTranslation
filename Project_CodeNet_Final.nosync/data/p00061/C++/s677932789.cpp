#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;

int main(){

  int a,b,z = 1,s[1000],n;
  vector < pair < int , int > > p;

  while(1){
    scanf("%d,%d",&a,&b);
    if(!a && !b) break;

    pair < int , int > k(b,a);
    p.push_back(k);

  }

  sort(p.begin(),p.end());
  reverse(p.begin(),p.end());
  s[0] = 1;

  for(int i=1;i<p.size();i++){
    if(p[i-1].first > p[i].first) z++;
    s[i] = z;
  }


  while(cin >> n){

    for(int i=0;i<p.size();i++){
      if(p[i].second == n){
	cout << s[i] << endl;
	break;
      }
    }
  }

}