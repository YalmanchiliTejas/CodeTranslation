#include<bits/stdc++.h>
using namespace std;

int main(){
      int n,m;cin >> n >> m;
      char arr[n + 10][m + 10];
      set<int> forbidr;
      set<int> forbidc;
      bool currC[m + 10];
      for(int i = 0;i < m;i++)currC[i] = false;
      for(int i = 0;i < n;i++){
            bool currR = false;
            for(int j = 0;j < m;j++){
                  cin >> arr[i][j];
                  if(arr[i][j] == '#'){
                        currR = true;
                        currC[j] = true;
                  }
                  if(i == n - 1){
                        if(currC[j] == false)forbidc.insert(j);
                  }
            }
            if(!currR)forbidr.insert(i);
      }
      for(int i = 0;i < n;i++){
            bool flag = false;
            for(int j = 0;j < m;j++){
                  if(forbidc.count(j) == 0 && forbidr.count(i) == 0){
                        cout << arr[i][j];
                        flag = true;
                  }
            }
            if(flag)cout << "\n";
      }
}