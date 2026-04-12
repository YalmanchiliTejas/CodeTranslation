#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <utility>
#include <numeric>
#include <stack>
#include <queue>
using namespace std;
#define ll long long
#define INF 1000000007
using P = pair<int, int>;
int main(){
    int h,w;
    cin>>h>>w;
    char a[100][100];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<h;i++){
        int count=0;
        for(int j=0;j<w;j++){
            if(a[i][j]=='.')count++;
        }
        if(count==w){
            for(int j=i+1;j<h;j++){
                for(int k=0;k<w;k++){
                    a[j-1][k]=a[j][k];
                }
            }
            h--;
            i--;
        }
    }
    for(int i=0;i<w;i++){
        int count=0;
        for(int j=0;j<h;j++){
            if(a[j][i]=='.')count++;
        }
        if(count==h){
            for(int j=i+1;j<w;j++){
                for(int k=0;k<h;k++){
                    a[k][j-1]=a[k][j];
                }
            }
            w--;
            i--;
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }
    return 0;
}
