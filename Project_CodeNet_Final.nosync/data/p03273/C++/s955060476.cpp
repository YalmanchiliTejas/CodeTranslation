#include <iostream>
#include <string>
#include <algorithm>

#define dbg if(0)
using namespace std;
#define ll long long

int main(){
    int h,w;
    cin >> h>>w;
    string rows[h];
    bool column[w];
    bool row[h];
    for(int i=0;i<h;i++){
        row[i]=false;
    }
    for(int i=0;i<w;i++){
        column[i]=false;
    }
    for(int i=0;i<h;i++){
        cin >>rows[i];
        for(int j=0;j<w;j++){
            if (rows[i][j]=='#'){
                column[j]=true;
                row[i]=true;
            }
        }
    }
    for(int i=0;i<h;i++){
        cin >>rows[i];
        bool f=false;
        for(int j=0;j<w;j++){
            if(column[j]&&row[i]){
                cout <<rows[i][j];
                f=true;
            }
        }
        if(f)cout <<endl;
    }

    return 0;
}