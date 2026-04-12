#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

int main(void){
    int h,w;
    cin >> h >> w;
    char a[h][w];
    rep(i,h){
        rep(j,w){
            char x;
            cin >> x;
            a[i][j] = x;
        }
    }
    bool flag = 1;
    rep(i,h){
        flag = 1;
        rep(j,w){
            if(a[i][j]=='#'){
                flag = 0;
                break;
            }
        }
        if(flag ==1){
            rep(j,w){
                a[i][j] = '0';
            }
        }
    }
  
    rep(j,w){
        flag = 1;
        rep(i,h){
            if(a[i][j]=='#'){
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            rep(i,h){
                a[i][j] = '0';
            }
        }
    }
  	
  	
    rep(i,h){
      int sum = 0;
        rep(j,w){
            if(a[i][j] != '0'){
                cout << a[i][j];
            }
          	else{
              sum++;
            }
        }
      if(sum!=w){
        cout << endl;
      }
    }
    
    
    
    return 0;
}




