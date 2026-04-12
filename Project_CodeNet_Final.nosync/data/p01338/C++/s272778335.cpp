#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int field[6][6];
int dp[6][6][1<<12];
int n;
const int INF=1000000000;
int seiseki[4];

// óÔsÌidxÔÚÌlðæèo·
int getValue(int s,int idx){
    int b1=((s>>idx*2)&1);
    int b2=((s>>idx*2+1)&1);
    return b1+2*b2;
}
// óÔsÌidxÔÚÉlxðZbg
void setValue(int &s,int idx,int x){
    int b1=((x>>0)&1);
    int b2=((x>>1)&1);
    if(b1==0)
        s&=~(1<<idx*2);
    else
        s|=(1<<idx*2);
    if(b2==0)
        s&=~(1<<(idx*2+1));
    else
        s|=(1<<(idx*2+1));
}

// (»Ýn_ÌxÀW,»Ýn_ÌyÀW,êÔµ½5}XÌóÔ
int rec(int x,int y,int s){
    if(x==4){
        x=0;
        y++;
        if(y==4){
            int res=0;
            // ¡ÌsÌlð0-4Ìn_ÌàÌð·×Ä«µí¹A»êðÔ·
            for(int i = 0; i < 5; i++)
                if(field[y][i]!=-1)
                    res+=seiseki[getValue(s,i)];
            return res;
        }
    }
    if(dp[y][x][s]!=INF)
        return dp[y][x][s];
    int maxCost=0;
    // »Ýn_ð½ñ·©
    for(int i = 0; i <= 3; i++){
        if(x==0){
            int ns=0;
            setValue(ns,5,getValue(s,4));
            setValue(ns,4,getValue(s,3));
            setValue(ns,3,getValue(s,2));
            setValue(ns,2,(getValue(s,1)+i)%4);
            setValue(ns,1,(max(0,field[y+1][x+1])+i)%4);
            setValue(ns,0,(max(0,field[y+1][x])+i)%4);
            // ¶ãÌêÌXRAðmè³¹é
            int res=0;
            if(field[y][x]!=-1)
                res+=seiseki[(getValue(s,x)+i)%4];
            // rec
            maxCost=max(maxCost,res+rec(x+1,y,ns));
        }
        else{
            int ns=0;
            for(int j = 0; j < 6; j++){
                if(j==x||j==x+2)
                    setValue(ns,j,(getValue(s,j)+i)%4);
                else
                    setValue(ns,j,getValue(s,j));
            }
            setValue(ns,x+1,(max(0,field[y+1][x+1])+i)%4);
            // ¶ãÌêÌXRAðmè³¹é
            int res=0;
            if(field[y][x]!=-1)
                res+=seiseki[(getValue(s,x+1)+i)%4];
            // EãÌXRAàmè³¹é
            if(x==3){
                if(field[y][x+1]!=-1)
                    res+=seiseki[(getValue(s,x+2)+i)%4];
            }
            maxCost=max(maxCost,res+rec(x+1,y,ns));
        }
    }
    return dp[y][x][s]=maxCost;
}


int main(){
    seiseki[0]=0;
    seiseki[1]=60;
    seiseki[2]=70;
    seiseki[3]=80;
    cin>>n;
    for(int q=0;q<n;q++){
        for(int i = 0; i < 6; i++)
            for(int j = 0; j < 6; j++)
                for(int k = 0; k < (1<<12); k++)
                    dp[i][j][k]=INF;
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                cin>>field[i][j];
                field[i][j]--;
            }
        }
        int s=0;
        for(int i = 0; i < 5; i++)
            setValue(s,i,max(0,field[0][i]));
        int res=rec(0,0,s);
        cout<<res<<endl;
    }
    return 0;
}