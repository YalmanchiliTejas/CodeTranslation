#include<iostream>
#include<string>
#include<queue>
using namespace std;
class info{
    public:
    int x,y;
    int sz;
};

int main(){
    int H,W;
    cin>>H>>W;
    string str[9];
    for(int i=0;i<H;i++){
        cin>>str[i];
    }
    int tot=0;
    for(int i=0;i<H;i++){
        for(int j=0;j<str[i].size();j++){
            if(str[i][j]=='#') tot++;
        }
    }
    queue<info> q;
    info aa;
    aa.x=0; aa.y=0; aa.sz=1;
    q.push(aa);
    bool fl=false;
    while( !q.empty() ){
        info i=q.front(); q.pop();
        if(i.x==W-1 && i.y==H-1){
            if(i.sz==tot){
                fl=true;
                break;
            }
        }
        if(i.x+1<W && str[i.y][i.x+1]=='#'){
            info inpu=i;
            inpu.x++;
            inpu.sz++;
            q.push(inpu);
        }
        if(i.y+1<H && str[i.y+1][i.x]=='#'){
            info inpu=i;
            inpu.y++;
            inpu.sz++;
            q.push(inpu);
        }
    }
    if(fl){
        cout<<"Possible"<<endl;
    }else{
        cout<<"Impossible"<<endl;
    }
    
    return 0;
}
