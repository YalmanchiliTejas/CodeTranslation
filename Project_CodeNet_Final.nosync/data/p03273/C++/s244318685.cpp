#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mod 1000000007
typedef long long ll;

int main(){
    int h,w;
    cin >> h >> w;
    char a[h][w];
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
            cin >> a[i][j];
    while(true){
        bool change = 0;

        for(int i=0;i<h;i++){
            bool allw = true;
            for(int j=0;j<w;j++){
                if(a[i][j]=='#'){
                    allw = false;
                    break;
                }
            }
            if(allw){
                change = 1;
                for(int k=i+1;k<h;k++){
                    for(int j=0;j<w;j++)
                        a[k-1][j] = a[k][j];
                }
                h--;
                break;
            }
        }

        for(int j=0;j<w;j++){
            bool allw = true;
            for(int i=0;i<h;i++){
                if(a[i][j]=='#'){
                    allw = false;
                    break;
                }
            }
            if(allw){
                change = 1;
                for(int k=j+1;k<w;k++){
                    for(int i=0;i<h;i++)
                        a[i][k-1] = a[i][k];
                }
                w--;
                break;
            }
        }
        if(!change)
            break;
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++)
            cout << a[i][j];
        cout << endl;
    }
}