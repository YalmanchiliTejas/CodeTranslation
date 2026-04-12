#define _GLIBCXX_DEBUG //GCC環境での[]デバッグ
#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < n;i++)
using namespace std;
int main(void){
    // Your code here!
    int H, W;
    cin >> H >> W;
    std::vector<std::vector<char>> mass(H,std::vector<char>(W));
    rep(i, H){
        rep(j, W){
            cin >> mass[i][j];
        }
    }
    
    //横が一致
    int cnt = 0;
    std::vector<int> yoko(W+H, -1);
    rep(i, H){
        rep(j, W){
            if(mass[i][j] == '.')cnt++;
        }   
       // cout << cnt <<  endl;
        if(cnt == W ) {
            yoko[i] = i;
          //  cout << yoko[i];
        }
        cnt = 0;
    }    
    
    //縦が一致
    cnt = 0;
    std::vector<int> tate(W+H, -1);
    rep(j, W){
        rep(i, H){
            if(mass[i][j] == '.')cnt++;
        }   
       // cout << cnt <<  endl;
        if(cnt == H ) {
            tate[j] = j;
          //  cout << tate[j];
        }
        cnt = 0;
    }    
    
    int flag1 = 0, flag2 = 0;
    rep(i, H){
        rep(k,yoko.size()){
            if(i == yoko[k]){
                flag1 = 1;
                break;
            }
        } 
        if(flag1 == 1) {
            flag1 =0;
            continue;
        }
        rep(j, W){
            rep(k,tate.size()){
                if(j == tate[k]){
                    flag2 = 1;
                    break;
                }
            } 
            if(flag2 == 1) {
                flag2 =0;
                continue;
            }            
            
            cout << mass[i][j]  ;
            
            
        }
    cout << endl;
    }
    
    
}
