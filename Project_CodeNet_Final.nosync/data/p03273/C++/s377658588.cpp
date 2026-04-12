#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
int main(){
    int h,w;
    cin >> h >> w;
    string a[h];

    for(int i=0;i<h; i++){
        cin >> a[i];
    }   
    int z[h]={0};
    int z2[w]={0};
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(a[i][j]=='#'){
                z[i]++;
                z2[j]++;
            }
        }
    }

    for(int i=0; i<h; i++){
        if(z[i]){
            for(int j=0; j<w; j++){
                if(z2[j]){
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }
}
