#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int prev(int i, int n){
   if(i <= 0) return n;
   else return i -1;
}

int next(int i, int n){
   if(i >= n) return 0;
   else return i + 1;
}

int main()
{
   int n;
   string s;
   cin >> n >> s;
   
   rep(k,2){
      //0番目２通り
      vector<int> ans(n,-1);
      ans[0] = k;
      rep(j,2){
         //n番目2通り
       //  rep(x,n)ans[x] =-1;
         ans[n -1] = j;
         //全部埋めてみる
         rep(i,n-2){
            if((ans[i] == 1) && (ans[prev(i,n-1)] == 1))
            {
               if(s[i] == 'o') ans[next(i,n-1)] = 1;
               else ans[next(i,n-1)] = 0;
            } 
            else if((ans[i] == 1) && (ans[prev(i,n-1)] == 0))
            {
               if(s[i] == 'o') ans[next(i,n-1)] = 0;
               else ans[next(i,n-1)] = 1;
            } 
            else if((ans[i] == 0) && (ans[prev(i,n-1)] == 1))
            {
               if(s[i] == 'o') ans[next(i,n-1)] = 0;
               else ans[next(i,n-1)] = 1;
            } 
            else if((ans[i] == 0) && (ans[prev(i,n-1)] == 0))
            {
               if(s[i] == 'o') ans[next(i,n-1)] = 1;
               else ans[next(i,n-1)] = 0;
            }
         }
         //n-1とn番目の時に辻褄が合えばOK
         bool ok = true;
         if(s[n -2] == 'o'){
            if(ans[n-2] == 1) {
               if(ans[prev(n-2,n-1)] == 1 && ans[next(n-2,n-1)] == 0) ok = false;
               else if(ans[prev(n-2,n-1)] == 0 && ans[next(n-2,n-1)] == 1) ok = false;
            }
            else{
               if(ans[prev(n-2,n-1)] == 1 && ans[next(n-2,n-1)] == 1) ok = false;
               else if(ans[prev(n-2,n-1)] == 0 && ans[next(n-2,n-1)] == 0) ok = false;
            }
         } else {
             if(ans[n-2] == 1) {
               if(ans[prev(n-2,n-1)] == 1 && ans[next(n-2,n-1)] == 1) ok = false;
               else if(ans[prev(n-2,n-1)] == 0 && ans[next(n-2,n-1)] == 0) ok = false;
            }
            else{
               if(ans[prev(n-2,n-1)] == 1 && ans[next(n-2,n-1)] == 0) ok = false;
               else if(ans[prev(n-2,n-1)] == 0 && ans[next(n-2,n-1)] == 1) ok = false;
            }
         }
         if(s[n-1] == 'o'){
            if(ans[n-1] == 1) {
               if(ans[prev(n-1,n-1)] == 1 && ans[next(n-1,n-1)] == 0) ok = false;
               else if(ans[prev(n-1,n-1)] == 0 && ans[next(n-1,n-1)] == 1) ok = false;
            }
            else{
               if(ans[prev(n-1,n-1)] == 1 && ans[next(n-1,n-1)] == 1) ok = false;
               else if(ans[prev(n-1,n-1)] == 0 && ans[next(n-1,n-1)] == 0) ok = false;
            }
         } else {
             if(ans[n-1] == 1) {
               if(ans[prev(n-1,n-1)] == 1 && ans[next(n-1,n-1)] == 1) ok = false;
               else if(ans[prev(n-1,n-1)] == 0 && ans[next(n-1,n-1)] == 0) ok = false;
            }
            else{
               if(ans[prev(n-1,n-1)] == 1 && ans[next(n-1,n-1)] == 0) ok = false;
               else if(ans[prev(n-1,n-1)] == 0 && ans[next(n-1,n-1)] == 1) ok = false;
            }
         }
         if(ok){
            //rep(i,n) cout << ans[i];
            rep(i,n) if(ans[i] == 1) cout <<'S'; else cout << 'W';
            cout << endl;
            return 0;
         }
      }
   }
   cout << -1 << endl;
}