      #include <iostream>
      #include <string>
      #include <vector>
      #include <algorithm>
      #include <utility>
      using namespace std;
      typedef long long ll;
      #define rep(i, n) for (int i=0;i < (int)(n);i++)

      int main(){
         int n;
         string s;
         cin >> n >> s;
         vector<int> v(n,-1);
         int p[] = {1,1,0,0};
         int q[] = {1,0,1,0};
         bool f = false;
         bool can = false;

         rep(k,4){
            f = false;
            can = false;
            v[0] = p[k];
            v[1] = q[k];
             for (int i = 1;i < n-1;i++){
                if (v[i] == 0){
                   if (s[i] == 'o'){
                      v[i+1] = v[i-1];
                   }
                   else if(s[i] == 'x'){
                      if (v[i-1] == 0) v[i+1] = 1;
                      else v[i+1] = 0;
                   }
                }
                else{
                   if (s[i] == 'o'){
                      if (v[i-1] == 0) v[i+1] = 1;
                      else v[i+1] = 0;
                   }
                   else{
                      v[i+1] = v[i-1];
                   }
                }
             }
               if (v[n-1] == 0){
                   if (s[n-1] == 'o'){
                      if (v[n-2] == v[0]) {
                         f = true;
                      }
                      else continue;
                   }
                   else if(s[n-1] == 'x'){
                      if (v[n-2] != v[0]){
                         f = true;
                      }
                      else continue;
                   }
                }
                else{
                   if (s[n-1] == 'o'){
                      if (v[n-2] != v[0]){
                         f= true;
                      }
                      else continue;
                   }
                   else {
                      if (v[n-2] == v[0]){
                         f = true;
                      }
                      else continue;
                   }
                }
                if (f){
                  if (v[0] == 0){
                     if (s[0] == 'o'){
                        if (v[n-1] == v[1]) {
                           can = true;
                           break;
                        }
                        else continue;
                     }
                     else if(s[0] == 'x'){
                        if (v[n-1] != v[1]){
                            can = true;
                           break;
                        }
                        else continue;
                     }
                  }
                  else{
                     if (s[0] == 'o'){
                        if (v[n-1] != v[1]){
                            can = true;
                            break;
                        }
                        else continue;
                      }
                     else {
                        if (v[n-1] == v[1]){
                           can = true;
                           break;
                        }
                        else continue;
                     }
                  }
                }
         }
         if (can){
            rep(i,n){
               if (v[i] == 0) cout << 'S';
               else cout << 'W';
            }
            cout << endl;
         }
         else cout << -1 << endl;

         
         return 0;
         
      }

