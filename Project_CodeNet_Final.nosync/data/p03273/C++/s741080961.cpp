#include<bits/stdc++.h>
#define rp(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll=long long;

int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<char>> grid(h,vector<char>(w));
    vector<int> hok(h,0),wok(w,0);
    rp(i,h){
        rp(j,w){
            cin >> grid.at(i).at(j);
            if(grid[i][j]=='#') {hok.at(i)=1; wok.at(j)=1;}
        }
    }
    rp(i,h){
        bool line=false;
        rp(j,w){
            if(hok.at(i)*wok.at(j)==1){
                cout << grid[i][j];
                line=true;
            }
        }
        if(line)
        cout << endl;
    }
    return 0;
}