#include <iostream>
#include <vector>
using namespace std;
int main(void){
    // Your code here!
    
    int N, M;
    cin >> N >> M;
    
    vector<vector<char>> a(N, vector<char>(M));
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> a[i][j];
        }
    }
    
    for(int i = 0; i < N; i++){
        
        bool b = false;
        
        for(int j = 0; j < M; j++){
            
            if(a[i][j] != '.'){
                b = false;
                break;
            }
 
            else
                b = true;
        }
        
        if(b){
            for(int j = 0; j < M; j++){
                a[i][j] = 'X';
            }
        }
    }
    
    
    for(int j = 0; j < M; j++){
        
        bool b = false;
        
        for(int i = 0; i < N; i++){
            
            if(a[i][j] == 'X' || a[i][j] == '.')
                b = true;
                
            else{
                b = false;
                break;
            }
        }
        
        if(b){
            for(int i = 0; i < N; i++){
                a[i][j] = 'X';
            }
        }
    }
    
    
    for(int i = 0; i < N; i++){
        bool b = false;
        for(int j = 0; j < M; j++){
            if(a[i][j] != 'X'){
                cout << a[i][j];
                b = true;
            }
        }
        if(b)
            cout << endl;
    }
    
}
