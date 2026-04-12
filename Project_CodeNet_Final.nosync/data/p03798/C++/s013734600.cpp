#include <bits/stdc++.h>
//0 sheep
//1 wolf
using namespace  std;
const int maxn = 1e5+10;
int n;
string s;
int b[4][2]={{0,0},{0,1},{1,0},{1,1}};
int ans[maxn];
bool check() {
    char c;
    if(ans[0]){
        if(ans[n-1]==ans[1]){
            c = 'x';
        }else{
            c = 'o';
        }
        if(s[0]!=c)
            return false;
    }else{
        if(ans[n-1]==ans[1]){
            c = 'o';
        }else{
            c = 'x';
        }
        if(s[0]!=c)
            return false;
    }
    for(int i=1; i<n-1; i++){
        if(ans[i]){
            if(ans[i-1]==ans[i+1]){
                c = 'x';
            }else{
                c = 'o';
            }
            if(s[i]!=c)
                return false;
        }else{
            if(ans[i-1]==ans[i+1]){
                c = 'o';
            }else{
                c = 'x';
            }
            if(s[i]!=c)
                return false;
        }
    }
    if(ans[n-1]){
        if(ans[n-2]==ans[0]){
            c = 'x';
        }else{
            c = 'o';
        }
        if(s[n-1]!=c)
            return false;
    }else{
        if(ans[n-2]==ans[0]){
            c = 'o';
        }else{
            c = 'x';
        }
        if(s[n-1]!=c)
            return false;
    }
    return true;
}
int main() {
//    freopen("input.txt","r",stdin);
   cin >> n >> s;
   for(int i=0; i<4; i++){
       for(int j=0; j<2; j++){
           ans[j] = b[i][j];
       }
       for(int j=2; j<n; j++){
           if(ans[j-1]==1&&s[j-1]=='x'){
               ans[j]=ans[j-2];
           }else if(ans[j-1]==1&&s[j-1]=='o'){
               ans[j]=!ans[j-2];
           }else if(ans[j-1]==0&&s[j-1]=='o'){
               ans[j]=ans[j-2];
           }else{
               ans[j]=!ans[j-2];
           }
       }
//       for(int j=0; j<n; j++){
//           cout << ans[j];
//       }
//       cout<<endl;
       if(check()){
           for(int j=0; j<n; j++){
               if(ans[j]){
                   cout <<"W";
               }else{
                   cout <<"S";
               }
           }
           cout << endl;
           return 0;
       }
   }
   cout << -1 << endl;
   return 0;
}
