#include <iostream>
using namespace std;
int main(){
    int a,b,c,d,e,f,g,i,j,k,l,w,h;
    cin>>h>>w;
    string s[h],t;
    for(a=0;a<h;a++){
        c=1;
        cin>>s[a];
        for(b=0;b<w;b++){
            if(s[a][b]=='#'){
                c=0;
            }
        }
        if(c==1){
            for(d=0;d<w;d++){
                s[a][d]='!';
            }
        }
    }
    for(e=0;e<w;e++){
        c=1;
        for(f=0;f<h;f++){
            if(s[f][e]=='#'){
                c=0;
            }
        }
        if(c==1){
            for(g=0;g<h;g++){
                s[g][e]='!';
            }
        }
    }
    for(i=0;i<h;i++){
        l=0;
        for(j=0;j<w;j++){
            if(s[i][j]!='!'){
                cout<<s[i][j];
                l=1;
            }
        }
        if(l==1){
            cout<<endl;
        }
    }
}