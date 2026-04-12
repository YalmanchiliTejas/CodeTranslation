#include <bits/stdc++.h>
using longlong=long long;

int main(){
    std::cin.tie(nullptr);std::cin.sync_with_stdio(false);
    int h, w; std::cin >> h >> w;
    std::vector<std::vector<char>>grid(h,std::vector<char>(w));
    for(int i=0;i<h;i++)for(int j=0;j<w;j++){
        std::cin>>grid.at(i).at(j);
    }
    int h0=0;
    for(int i=0;i<h;i++){
        bool found=false;
        for(int j=0;j<w;j++){
            grid.at(h0).at(j)=grid.at(i).at(j);
            if(grid.at(h0).at(j)=='#')found=true;
        }
        if(found)h0++;
    }
    int w0=0;
    for(int j=0;j<w;j++){
        bool found=false;
        for(int i=0;i<h;i++){
            grid.at(i).at(w0)=grid.at(i).at(j);
            if(grid.at(i).at(w0)=='#')found=true;
        }
        if(found)w0++;
    }
    for(int i=0;i<h0;i++){
        for(int j=0;j<w0;j++){
            std::cout<<grid.at(i).at(j);
        }
        std::cout<<std::endl;
    }
}