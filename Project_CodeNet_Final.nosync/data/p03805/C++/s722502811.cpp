#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  vector<set<int>> edge(n);
  for(int i=0;i<m;i++){
    int b,c;
    cin>>b>>c;
    edge.at(b-1).insert(c-1);
    edge.at(c-1).insert(b-1);
  }
  int ans=0;
  
    vector<int> a(n-1);
    for(int i=0;i<n-1;i++){
      a.at(i)=i+1;
    }
    do{
        vector<int> e(n);
        bool cur=true;
        for(int i=0;i<n-1;i++){
            e.at(i+1)=a.at(i);
            if(!edge.at(e.at(i+1)).count(e.at(i))){
                cur=false;
            }
        }
        if(cur){
            ans++;
        }
    }while(next_permutation(a.begin(),a.end()));
  cout<<ans<<endl;
}