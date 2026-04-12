#include <bits/stdc++.h>
using namespace std;

int H,W,h[110],w[110],k;
char m[110][110];

int main(){
    while(cin>>H>>W){
        memset(h,0,sizeof(h));
        memset(w,0,sizeof(w));
        for(int i=0; i<H; i++){
            k = 0;
            for(int j=0; j<W; j++){
                cin>>m[i][j];
                if(m[i][j]=='.')
                    k++;
            }
            if(k==W){
                w[i] = 1;//哪一排
            }
        }

        for(int i=0; i<W; i++){
            k = 0;
            for(int j=0; j<H; j++){
                if(m[j][i]=='.')
                    k++;
            }
            if(k==H){
                h[i] = 1;//哪一列
            }
        }

        for(int i=0; i<H; i++){
            if(w[i]==1)
                continue;
            for(int j=0; j<W; j++){
                if(h[j]==1)
                    continue;
                cout<<m[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}
