#include<iostream>
using namespace std;

struct Pass{
    int start,fin;
};

int inf=100;

int main(){
    string str[8];
    Pass line[8];
    int h,w;
    bool aflag=true;
    cin>>h>>w;
    for(int i=0; i<h; i++){
        bool sflag=false;
        bool fflag=false;
        cin>>str[i];
        for(int j=0; j<str[i].length(); j++){
            if(str[i][j]=='#'&&!sflag&&!fflag){
                line[i].start=j;
                sflag=true;
            }
            if((str[i][j+1]=='.'&&!fflag&&sflag)||(j==w-1&&!fflag&&sflag)){
                line[i].fin=j;
                fflag=true;
            }
            else if(fflag&&str[i][j]=='#')line[i].fin=inf;
        }
    }
    for(int i=0; i<h-1; i++){
        aflag*=(line[i].fin==line[i+1].start);
    }
    if(aflag)cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;

    return 0;
}
