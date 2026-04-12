#include <cstdio>
#include <cstring>

typedef unsigned long long int ull;

int N;

ull targetOfRow[505],targetOfCol[505];
ull opcatOfRow[505],opcatOfCol[505];
ull matrix[505][505];

int zeroCountOfRow[505],zeroCountOfCol[505];

bool check(){
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

int main(){

    scanf("%d",&N);

    for(int i=1;i<=N;i++) scanf("%llu",opcatOfRow+i);
    for(int i=1;i<=N;i++) scanf("%llu",opcatOfCol+i);
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

        for(int r=1;r<=N;r++){
            //今の桁を何にするかを表す
            auto bitTarget=(targetOfRow[r]>>bit)&opcatOfRow[r];
            if (!bitTarget||zeroCountOfRow[r]<N) continue;
            
            int c=1;
            while(c<=N){
                if (opcatOfCol[c]==0&&(targetOfCol[c]&mask)==0&&zeroCountOfCol[c]>1) break;
                c++;
            }
            if (c>N) continue;
            matrix[r][c]|=mask;
            zeroCountOfCol[c]--;
            zeroCountOfRow[r]--;
        }

        for(int c=1;c<=N;c++){
            //今の桁を何にするかを表す
            auto bitTarget=(targetOfCol[c]>>bit)&opcatOfCol[c];
            if (!bitTarget||zeroCountOfCol[c]<N) continue;
            int r=1;
            while(r<=N) { 
                if (opcatOfRow[r]==0&&(targetOfRow[r]&mask)==0&&zeroCountOfRow[r]>1) break;
                r++;
            }
            if (r>N) continue;
            matrix[r][c]|=mask;
            zeroCountOfCol[c]--;
            zeroCountOfRow[r]--;
        }

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