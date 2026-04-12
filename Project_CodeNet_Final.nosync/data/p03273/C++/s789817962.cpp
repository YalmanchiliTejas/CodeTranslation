#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <climits>
int main()
{
    long H,W;
    std::cin >> H >> W;
    char a[100][100];
    for(long i=0; i<H; i++){
        for(long j=0; j<W; j++){
            std::cin >> a[i][j];
        }
    }
    long count;
    std::vector<long> Hs;
    for(long i=0; i<H; i++){
        count=0;
        for(long j=0; j<W; j++){
            if(a[i][j]=='.'){
                count++;
            }
        }
        if(count==W){
            Hs.push_back(i);
        }
    }
    std::vector<long> Ws;
    for(long j=0; j<W; j++){
        count=0;
        for(long i=0; i<H; i++){
            if(a[i][j]=='.'){
                count++;
            }
        }
        if(count==H){
            Ws.push_back(j);
        }
    }

    for(long i=0;i<H; i++){
        auto result1=std::find(Hs.begin(),Hs.end(),i);
        for(long j=0; j<W; j++){
            auto result2=std::find(Ws.begin(),Ws.end(),j);
            if(result1==Hs.end() && result2==Ws.end()){
                std::cout << a[i][j];
            }            
        }
        if(result1==Hs.end()){
            std::cout << std::endl;
        }
    }
    return 0;
}