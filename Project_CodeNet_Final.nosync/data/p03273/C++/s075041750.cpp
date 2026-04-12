#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int,int> P;
const int INF=(int)1e9;
const int MOD=(int)1e9+7;
struct Accelerate_Cin{
    Accelerate_Cin(){
        cin.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(20);
    };
};

int main(){
 int H,W;
 cin>>H>>W;
 char c[105][105];
 set<int>seth;
 set<int>setw;
 for(int h=1;h<=H;h++){
   int cont=0;
   for(int w=1;w<=W;w++){
     cin>>c[h][w];
     if(c[h][w]=='#')cont++;
   }
   if(cont==0)seth.insert(h);
 }

 for(int w=1;w<=W;w++){
   int cont=0;
   for(int h=1;h<=H;h++){
     if(c[h][w]=='#')cont++;
   }
   if(cont==0)setw.insert(w);
 }

 for(int h=1;h<=H;h++){
   if(seth.find(h)!=seth.end())continue;
   for(int w=1;w<=W;w++){
     if(setw.find(w)!=setw.end())continue;
     cout<<c[h][w];
   }
   cout<<endl;
 }
 return 0;
}
