#include<bits/stdc++.h>
using namespace std;
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define ll long long 
#define mod 1000000007
void setIO(string name) {
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen((name+".in").c_str(),"r",stdin);
  freopen((name+".out").c_str(),"w",stdout);
}
void fast(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
}
int main() {
   fast();
   int h,w;
   cin>>h>>w;
   char a[h][w];
   for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>a[i][j];
    }
   }
   int x=0;
   int f=0;
   int y=0;
   int k=0;
   while(x<h){
    int t;
     for(int i=0;i<w;i++){
       if(a[x][i]=='#'){
          t=i;
          break;
       }
     }
     if(t==y){
      f=1; 
      int p;
      for(int i=y;i<w;i++){
        if(a[x][i]=='#'){
          k++;
          p=i;
        }else{
          break;
        }
      }
      y=p;


     }else{
      f=0;
      break;
     }
     x++;
     
   }
   if(!f){
     cout<<"Impossible"<<"\n";
   }else{
    int l=0;
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        if(a[i][j]=='#'){
          l++;
        }
      }
    }
    if(l==k){
        
      cout<<"Possible"<<"\n";
    }else{
        //cout<<l<<" "<<k<<"\n";
      cout<<"Impossible"<<"\n";
    }
   }
   




} 