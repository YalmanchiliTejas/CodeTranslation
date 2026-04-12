#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main(){
    int H, W;
    char a[110][110];
    set<int> Hbacket;
    set<int> Wbacket;
    bool Wflag, Hflag;

    cin >> H >> W;
    for(int i = 0 ; i < H ; ++i){
        for(int j = 0; j < W; ++j){
            cin >> a[i][j];
        }
    }

    for(int i = 0 ; i < H ; ++i){
        Wflag = false;
        for(int j = 0; j < W; ++j){
            if(a[i][j] == '#'){
                Wflag = true;
            }
            if(Wflag){
                Wbacket.insert(j);
            }
            Wflag = false;
        }
    }

    for(int j = 0 ; j < W ; ++j){
        Hflag = false;
        for(int i = 0; i < H; ++i){
            if(a[i][j] == '#'){
                Hflag = true;
            }
            if(Hflag){
                Hbacket.insert(i);
            }
            Hflag = false;
        }
    }

    for(int i = 0 ; i < H; ++i){
        if(!Hbacket.count(i)){
            continue;
        }
        for(int j = 0; j < W; ++j){
           if(!Wbacket.count(j)){
               continue;
           }
           cout << a[i][j]; 
        }
        cout << endl;
    }  

}