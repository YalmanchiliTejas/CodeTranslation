#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct P{
    int num;
    int point;
    int rank;
    static bool more (const P& left,const P& right){
        return left.point > right.point;
    }
};

int main(){
    int n,cnt=0;
    vector <P> data;
    P tmp;
    while(1){
        scanf("%d,%d",&tmp.num,&tmp.point);
        if(tmp.num == 0 && tmp.point == 0) break;
        data.push_back(tmp);
        cnt++;
    }
    sort(data.begin(),data.end(),P::more);
    for(int i=0,rank=1;i<cnt;i++){
        if(i == 0) data[i].rank = rank;
        else if(data[i].point == data[i-1].point) data[i].rank = rank;
        else if(data[i].point < data[i-1].point){
            rank++;
            data[i].rank= rank;
        }
    }
    
    while(scanf("%d",&n) != EOF){
        for(int i=0;i<cnt;i++){
            if(data[i].num == n){
                cout << data[i].rank << endl;
                break;
            }
        }
    }
}