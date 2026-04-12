#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<n;i++)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
int main(){
    int h,w;cin >>h >>w;
    
    char arr[h][w] = {};
    fo(i,h){
        fo(j,w){
            cin >> arr[i][j]; 
        }
    }
    int i=0,j=0;  
    while(i<h-1&&j<w-1){
        if(arr[i][j+1]=='#'&&arr[i+1][j]!='#'){
            for(int y = i+2; y<h;++y){
                if(arr[y][j]=='#'){
                    cout << "Impossible";return 0;
                }
            }
            ++j;
        }
        else if(arr[i+1][j]=='#'&&arr[i][j+1]!='#'){
            for(int z = j+2; z<w;++z){
                if(arr[i][z]=='#'){
                    cout << "Impossible";return 0;
                }
            }
            ++i;
        }
        else{
            cout << "Impossible";return 0;
        }
    }
    if(i==h-1){
        for(int k=j+1;k<w;++k){
            if(arr[h-2][k]=='#'){
                cout << "IMPOSSIBLE";return 0;
            }
        }
        cout << "Possible";return 0;
    }
    else{
        for(int p=i+1;p<h;++p){
            if(arr[p][w-2]=='#'){
                cout << "IMPOSSIBLE";return 0;
            }
        }
        cout << "Possible";return 0;
    } 
}
