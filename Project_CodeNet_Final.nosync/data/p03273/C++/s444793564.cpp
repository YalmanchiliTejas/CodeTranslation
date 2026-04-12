#include<bits/stdc++.h>
using namespace std;
int b,c,d,cb,cc;
char a[5000][5000];
int main(){
    cin>>b>>c;
    cb=b;
    cc=c;
    for(int i=0;i<b;i++){
        for(int u=0;u<c;u++){
            cin>>a[i][u];
        }
    }
    for(int rp=0;rp<12000;rp++){
            int ad=0;
        for(int i=0;i<b;i++){
            int ccc=0;
            for(int u=0;u<c;u++){
                if(a[i][u]=='#')ccc++;
            }
            if(ccc==0){
                for(int u=0;u<c;u++){
                    a[i][u]=a[i+1][u];
                    a[i+1][u]='.';
                }
            }
        }


        for(int i=0;i<c;i++){
            int ccc=0;
            for(int u=0;u<b;u++){
                if(a[u][i]=='#')ccc++;
            }
            if(ccc==0){
                for(int u=0;u<b;u++){
                    a[u][i]=a[u][i+1];
                    a[u][i+1]='.';
                }

            }
        }


    }
    int maxx=0,maxy=0;
    for(int i=0;i<b;i++){
        for(int u=0;u<c;u++){
            if(a[i][u]=='#'){
                maxx=max(maxx,i);
                maxy=max(maxy,u);
            }
        }
    }


    for(int i=0;i<maxx+1;i++){
        for(int u=0;u<maxy+1;u++){
            cout<<a[i][u];
        }cout<<endl;
    }





}
