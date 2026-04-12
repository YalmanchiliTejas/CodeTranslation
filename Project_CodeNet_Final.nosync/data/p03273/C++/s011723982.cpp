#include <iostream>

using namespace std;

int main()
{
int h,w;
cin>>h;
cin>>w;
char a[h][w];
int cw[w],ch[h];
for(int i=0;i<w;i++){
    cw[i]=0;
}
for(int i=0;i<h;i++){
    ch[i]=0;
}
for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
        cin>>a[i][j];
    }
}
for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
        if(a[i][j] == '.'){
            ch[i]++;
            cw[j]++;
        }

    }
}
for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
       if(ch[i]!=w&&cw[j]!=h){
            cout<<a[i][j];
        }

    }
     if(ch[i]!=w)
    cout<<endl;
}

    return 0;
}
