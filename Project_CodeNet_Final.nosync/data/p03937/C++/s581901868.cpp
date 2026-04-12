#include <bits/stdc++.h>
using namespace std;
#define N_PRIME 1000000007
#define ll int64_t


int main(void){
    int h,w;
    cin >> h >> w;
    bool mat[10][10];
    
    for(int i = 0 ; i < 10 ; i++ ){
        for(int j = 0 ; j < 10 ; j++ ){
            mat[i][j] = false;
        }
    }
    
    for(int i = 0 ; i < h ; i++ ){
        string s;
        cin >> s;
        
        for(int j = 0 ; j < w ; j++ ){
            // #がtrue
            mat[j+1][i+1] = s[j] == '#';
        }
    }
    
    
    int x = 1;
    int y = 1;
    
    while(true){
        if( x == w && y == h ){
            mat[x][y] = false;
            break;
        }
        if( x > w || y > h ){
            break;
        }
        
        if( mat[x+1][y] ){
            mat[x][y] = false;
            x++;
            
        }else if(mat[x][y+1] ){
            mat[x][y] = false;
            y++;
        }else{
            break;
        }
        
    }
    
    for(int i = 1 ; i <= w ; i++ ){
        for(int j = 1 ; j <= h ; j++ ){
            if( mat[i][j] ){
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }
    
    cout << "Possible"<< endl;
    
    
    
    
    
    
    return 0;
}
