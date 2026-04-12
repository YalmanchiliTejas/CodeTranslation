#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int H,W,h=0;
    vector<vector<char> > a;
    
    cin >> H >> W;
    for(int i=0;i<H;i++){
        vector<char> kari;
        bool flag=false;
        
        for(int j=0;j<W;j++){
            char x;cin >> x;
            if(x=='#')flag=true;
            
            kari.push_back(x);
        }
        if(flag){a.push_back(kari);h++;}
    }
    int flag[110]={0};
    for(int j=0;j<W;j++){
        for(int i=0;i<h;i++){
            if(a[i][j]=='#')flag[j]=1;
        }
    }
    
    for(int i=0;i<h;i++){
        for(int j=0;j<W;j++){
            if(flag[j]==0)continue;
            
            cout << a[i][j];
        }
        cout << "\n";
    }
    
    return 0;
}