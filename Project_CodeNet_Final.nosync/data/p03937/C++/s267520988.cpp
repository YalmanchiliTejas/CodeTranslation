#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    int h,w;
    cin >> h >> w;
    char A[9][9];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> A[i][j];
        }
    }
    
    bool flag = true;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(A[i][j] == '#'){
//                A[i][j] = '.';
//                if(A[i+1][j]=='#' && A[i][j+1]=='#' && i+1<h && j+1 <w){
//                    
//                    flag = false;
//                }
                if(A[i+1][j]=='#' && A[i][j+1]=='#'){
                    
                    flag = false;
                }
//                if( A[i-1][j]=='#' && A[i][j-1]=='#' && A[i][j+1]=='#'){
//                    
//                    flag = false;
//                }
                if(A[i-1][j+1] == '#'){
                    flag = false;
                }

            }
        }
    }
    if(flag) cout << "Possible";
    else cout << "Impossible";
    return 0;
}