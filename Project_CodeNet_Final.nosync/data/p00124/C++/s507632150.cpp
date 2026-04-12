#include<iostream>
#include<vector>
#include<algorithm>
#define F first
#define S second


using namespace std;

typedef pair<string,int> P; 
bool cmp(const P &p,const P &q){
  return p.S > q.S;
}

int main(){
  int n;
  bool first = true;
  while(cin >> n && n){
    if(!first)cout << endl;
    string s;
    first = false;  
    vector<P> vec;
    int a,b,c;
    for(int i=0;i<n;i++){
    cin >> s >> a >> b >> c;
    vec.push_back(P(s,a*3+b*0+c*1));
    }

    stable_sort(vec.begin(),vec.end(),cmp);
    //reverse(vec.begin(),vec.end());
    for(int i=0;i<n;i++){
      cout << vec[i].F << "," << vec[i].S << endl;
    }
 
  }
  return 0;
}