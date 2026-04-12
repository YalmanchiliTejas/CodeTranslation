#include <bits/stdc++.h>
#include <math.h>
using namespace std;
void ABC100(void);
void ABC101(void);
void ABC102(void);
void ABC103(void);
void ABC104(void);
void ABC105(void);
void ABC106(void);
void ABC107(void);
void ABC108(void);
void ABC109(void);

int main(void){
    ABC107();
}

void ABC107(){
    int h,w,i,j,k=0,count=0;
    cin>>h>>w;
    char c;
    char a[h][w],b[h][w];
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            cin>>a[i][j];
            if(a[i][j]=='.')count++;
        }
        if(count==w){
            i--;
            h--;
        }
        count=0;
    }
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            cerr<<a[i][j];
        }
        cerr<<endl;
    }
    count=0;
    cerr<<h<<w<<endl;
    for(j=0;j<w;j++){
        for(i=0;i<h;i++){
            if(a[i][j]=='.')count++;
        }
        if(count!=h){
            for(i=0;i<h;i++){
                b[i][j-k]=a[i][j];
            }
        }
        if(count==h){
            k++;
        }
        count=0;
    }
    cerr<<h<<w<<endl;
    for(i=0;i<h;i++){
        for(j=0;j<w-k;j++){
            cout<<b[i][j];
        }
        cout<<endl;
    }
}