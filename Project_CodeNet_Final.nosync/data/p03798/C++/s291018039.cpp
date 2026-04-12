#include <bits/stdc++.h>
#define For(i,n) for(int i=0; i<n; i++)
#define M0D 1000000007
using namespace std;
struct animal{
 bool sheep;
 char type;
};
int main(){
 int N;
 cin >> N;
 bool secess=false;
 struct animal line[N+3];
 for(int i=1; i<N+1; i++) cin >> line[i].type;
 line[0].type = line[N].type;
 line[N+1].type = line[1].type;
 line[N+2].type = line[2].type;
 line[0].sheep = true;
 line[1].sheep = true;
 for(int i=1; i<N+3; i++){
   if(line[i].type=='o' && line[i].sheep) line[i+1].sheep = line[i-1].sheep;
   else if(line[i].type=='o' && !line[i].sheep) line[i+1].sheep = !line[i-1].sheep;
   else if(line[i].type=='x' && line[i].sheep) line[i+1].sheep = !line[i-1].sheep;
   else if(line[i].type=='x' && !line[i].sheep) line[i+1].sheep = line[i-1].sheep;
 }
 if(line[0].sheep == line[N].sheep&&line[1].sheep == line[N+1].sheep) secess = true;
 if(!secess){
   line[1].sheep = false;
   for(int i=1; i<N+2; i++){
     if(line[i].type=='o' && line[i].sheep) line[i+1].sheep = line[i-1].sheep;
     else if(line[i].type=='o' && !line[i].sheep) line[i+1].sheep = !line[i-1].sheep;
     else if(line[i].type=='x' && line[i].sheep) line[i+1].sheep = !line[i-1].sheep;
     else if(line[i].type=='x' && !line[i].sheep) line[i+1].sheep = line[i-1].sheep;
   }
   if(line[0].sheep == line[N].sheep&&line[1].sheep == line[N+1].sheep) secess = true;
 }
 if(!secess){
   line[0].sheep = false;
   for(int i=1; i<N+2; i++){
     if(line[i].type=='o' && line[i].sheep) line[i+1].sheep = line[i-1].sheep;
     else if(line[i].type=='o' && !line[i].sheep) line[i+1].sheep = !line[i-1].sheep;
     else if(line[i].type=='x' && line[i].sheep) line[i+1].sheep = !line[i-1].sheep;
     else if(line[i].type=='x' && !line[i].sheep) line[i+1].sheep = line[i-1].sheep;
   }
   if(line[0].sheep == line[N].sheep&&line[1].sheep == line[N+1].sheep) secess = true;
 }
 if(!secess){
   line[1].sheep = true;
   for(int i=1; i<N+2; i++){
     if(line[i].type=='o' && line[i].sheep) line[i+1].sheep = line[i-1].sheep;
     else if(line[i].type=='o' && !line[i].sheep) line[i+1].sheep = !line[i-1].sheep;
     else if(line[i].type=='x' && line[i].sheep) line[i+1].sheep = !line[i-1].sheep;
     else if(line[i].type=='x' && !line[i].sheep) line[i+1].sheep = line[i-1].sheep;
   }
   if(line[0].sheep == line[N].sheep&&line[1].sheep == line[N+1].sheep) secess = true;
 }
 if(!secess) cout << "-1";
 else for(int i=1; i<N+1; i++) cout << (line[i].sheep ? "S" : "W");
 cout << endl;
 return 0;
}
