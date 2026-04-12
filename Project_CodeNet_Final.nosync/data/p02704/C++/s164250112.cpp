#include <cstdio>
#include <cstring>

typedef unsigned long long int ull;

int N;

ull targetOfRow[505],targetOfCol[505];
int opcatOfRow[505],opcatOfCol[505];
ull matrix[505][505];

int zeroCountOfRow[505],zeroCountOfCol[505];

bool check(){
    //
    for(int r=1;r<=N;r++){
        ull androw=-1,orrow=0ull,andcol=androw,orcol=orrow;
        for(int c=1;c<=N;c++){
            androw&=matrix[r][c];
            orrow|=matrix[r][c];
            andcol&=matrix[c][r];
            orcol|=matrix[c][r];
        }

        if (opcatOfRow[r]&&orrow!=targetOfRow[r]) return false;
        if (!opcatOfRow[r]&&androw!=targetOfRow[r]) return false;
        if (opcatOfCol[r]&&orcol!=targetOfCol[r]) return false;
        if (!opcatOfCol[r]&&andcol!=targetOfCol[r]) return false;
    }

    return true;
}

void simpleInference(int pos){
    for(int r=1;r<=N;r++){
        for(int c=1;c<=N;c++){
            //目標値の対応ビットを取り出す
            auto colBit=(targetOfCol[c]>>pos)&1;
            auto rowBit=(targetOfRow[r]>>pos)&1;

            if (colBit^opcatOfCol[c]) matrix[r][c]|=(colBit<<pos);

            if (rowBit^opcatOfRow[r]) matrix[r][c]|=(rowBit<<pos);

            if (rowBit==colBit) matrix[r][c]|=(rowBit<<pos);
        }
    }
}

void SpecialInference(ull targets[],ull targets2[],int ops1[],int ops2[],int zeros1[],int zeros2[],bool isRow,int pos){
    ull mask=(ull)1<<(ull)pos;
    for(int r=1;r<=N;r++){
        //今の桁を何にするかを表す
        auto bitTarget=(targets[r]>>pos)&ops1[r];
        if (!bitTarget||zeros1[r]<N) continue;
        
        int c=1;
        while(c<=N){
            if (ops2[c]==0&&(targets2[c]&mask)==0&&zeros2[c]>1) break;
            c++;
        }
        if (c>N) continue;
        if (isRow)
            matrix[r][c]|=mask;
        else 
            matrix[c][r]|=mask;
        zeros2[c]--;
        zeros1[r]--;
    }
}

int main(){

    scanf("%d",&N);

    for(int i=1;i<=N;i++) scanf("%d",opcatOfRow+i);
    for(int i=1;i<=N;i++) scanf("%d",opcatOfCol+i);
    for(int i=1;i<=N;i++) scanf("%llu",targetOfRow+i);
    for(int i=1;i<=N;i++) scanf("%llu",targetOfCol+i);

    for(int bit=0;bit<64;bit++){
        ull mask=(ull)1<<(ull)bit;

        simpleInference(bit);

        memset(zeroCountOfCol,0,sizeof(zeroCountOfCol));
        memset(zeroCountOfRow,0,sizeof(zeroCountOfRow));
        for(int r=1;r<=N;r++)
            for(int w=1;w<=N;w++)
                if ((mask&matrix[r][w])==0) zeroCountOfRow[r]++,zeroCountOfCol[w]++;

        SpecialInference(targetOfRow,targetOfCol,opcatOfRow,opcatOfCol,zeroCountOfRow,zeroCountOfCol,true,bit);
        SpecialInference(targetOfCol,targetOfRow,opcatOfCol,opcatOfRow,zeroCountOfCol,zeroCountOfRow,false,bit);
    }

    if (!check()){
        puts("-1");
        return 0;
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++)
            printf("%llu ",matrix[i][j]);
            putchar('\n');
    }

    return 0;
}