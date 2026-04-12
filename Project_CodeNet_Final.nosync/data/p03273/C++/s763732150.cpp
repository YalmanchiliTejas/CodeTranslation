#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int main(){
    int a,b,flag;
    cin >> a >>b;
    string c[a];
    for(int i=0;i<a;i++)
        cin >> c[i];
    bool an[a],mn[b];
    for(int i=0;i<a;i++){
        an[i]=false;
        for(int j=0;j<b;j++){
            if(c[i][j]=='#'){
           an[i]=true;
            }
        }
    }

    for(int i=0;i<b;i++){
        mn[i]=false;
        for(int j=0;j<a;j++){
            if(c[j][i]=='#'){
                mn[i]=true;
            }
        }
    }

    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            if(an[i]&&mn[j]){
                cout << c[i][j];
            }
        }
        cout << endl;
        }
    }
