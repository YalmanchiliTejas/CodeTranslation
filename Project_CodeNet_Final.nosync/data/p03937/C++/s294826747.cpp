#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;
vector<vector<int>> vec;
int h,w;

int main(){
    cin >> h >> w ;
    int c=0;
    vec.resize(h,vector<int>(w));
    for(int i=0;i<h;i++){
        string s;
        cin >> s;
        for(int j=0;j<w;j++){
            vec[i][j]=s[j];
            if(s[j]=='#'){
                c++;
            }
        }
    }
    queue<pair<int,int>> q;
    vector<vector<int>> reg(h,vector<int>(w));
    q.push(pair<int,int>(0,0));
    reg[0][0]=0;
    bool h1=true;
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        bool h2=false;
        vec[y][x]='.';
        if(y+1<h){
            if(vec[y+1][x]=='#'){
                q.push(pair<int,int>(y+1,x));
                reg[y+1][x]=reg[y][x]+1;
                h2=true;
            }
        }
        if(x+1<w){
            if(vec[y][x+1]=='#'){
                q.push(pair<int,int>(y,x+1));
                reg[y][x+1]=reg[y][x]+1;
                if(h2){
                    h1=false;
                    break;
                }
            }
        }
    }
    if(vec[h-1][w-1]=='#'||reg[h-1][w-1]!=h+w-2||(c-1)!=reg[h-1][w-1]){
        cout<<"Impossible"<<endl;
    }else{
        cout<<"Possible"<<endl;
    }
}