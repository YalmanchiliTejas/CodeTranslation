#include <vector>
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

int main(){
    int h,w,q;
    cin >> h >> w;
    vector<string>x(h);
    vector<int> y (h,0);
    vector<int> z (w,0);
    for(int i=0;i<h;i++){
        cin >> x[i];
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(x[i][j]=='#'){
                y[i]+=1; //0 dame
                z[j]+=1;
            }
        }
    }
    for(int i=0;i<h;i++){
        if(y[i]>0){
            for(int j=0;j<w;j++){
                if(z[j]>0){
                    cout << x[i][j];
                }
            }
            cout << "\n";
        }
    }
}