#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
 int n,m;
 cin>>n>>m;

 vector<pair<int,int>> path(m);
 vector<int> point(n);

 rep(i,n){
     point.at(i)=1+i;
 }

rep(i,m){
    int a,b;
    cin>>a>>b;
    path.at(i)=make_pair(a,b);
}

sort(path.begin(),path.end());
sort(point.begin(),point.end());

int sum=0;
do{
    if(point.at(0)==1){
        bool is_all_path=false;
        for (int i=0;i<n-1;i++){
            bool is_thispath=false;
         for(int j=0;j<m;j++){
             if(path.at(j).first==point.at(i)&&path.at(j).second==point.at(i+1)||
             path.at(j).second==point.at(i)&&path.at(j).first==point.at(i+1)){
                is_thispath=true;
                break;

             }
            }
            if(!is_thispath){
            is_all_path=false;
            break;
        
            }
            else{
            is_all_path=true;

            }
    
        }
        if(is_all_path){
        sum++;

        }
    }
}while(next_permutation(point.begin(),point.end()));
  cout<<sum<<endl;
}
