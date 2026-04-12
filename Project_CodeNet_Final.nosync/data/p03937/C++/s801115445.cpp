#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <deque>
#include <cctype>
#include <cstdio>
#include <math.h>
using namespace std;
int main(){
    int h,w;
    cin >> h >> w;
    string ans="Possible";
    int count = 0;
    int a[10][10]={};
    for(int i=0;i<h;i++){
        string x;
        cin >> x;
        for(int j=0;j<w;j++){
            if(x[j]=='.'){
                a[i][j]=0;
            }else{
                a[i][j]=1;
                count++;
            }
        }
    }
    
    if(count != h+w-1){
        ans="Impossible";
    }
    int x=0,y=0;
    int cnt=0;
    int cnt2=0;
    bool flagx = false;
    bool flagy = false;
    while(x<h-1||y<w-1){
        if(x==0&&y==0){
            if(a[x+1][y]==1){
                flagx = true;
                cnt++;
            }
            if(a[x][y+1]==1){
                flagy = true;
                cnt++;
            }
        }else{
            if(x<h){
            if(a[x+1][y]==1){
                flagx = true;
                cnt++;
            }
            }
            if(y<w){
            if(a[x][y+1]==1){
                flagy = true;
                cnt++;
            }
            }
            if(x!=0){
                if(a[x-1][y]==1){
                    cnt2++;
                }
            }
            if(y!=0){
                if(a[x][y-1]==1){
                    cnt2++;
                }
            }
        }
        if(cnt>1||cnt2>1){
            ans="Impossible";
            break;
        }
        if(flagy==true&&flagx==true){
            ans="Impossible";
            break;
        }else if(flagx==true){
                x++;
        }else if(flagy==true){
                y++;
            }else{
                ans="Impossible";
                break;
            }
        cnt=0;
        cnt2=0;
        flagx = false;
        flagy = false;
    }
    cout << ans << endl;
}