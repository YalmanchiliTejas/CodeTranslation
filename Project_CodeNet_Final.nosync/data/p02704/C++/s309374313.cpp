#include <cstdio>
#include <cstring>

typedef unsigned long long int ull;

int N;

const int MAXN=502;

struct info_t{
    ull targets[MAXN];
    int opcat[MAXN];
    int zeroCount[MAXN];
}row,col;

ull matrix[MAXN][MAXN];

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

        if (row.opcat[r]&&orrow!=row.targets[r]) return false;
        if (!row.opcat[r]&&androw!=row.targets[r]) return false;
        if (col.opcat[r]&&orcol!=col.targets[r]) return false;
        if (!col.opcat[r]&&andcol!=col.targets[r]) return false;
    }

    return true;
}

void simpleInference(int pos){
    for(int r=1;r<=N;r++){
        for(int c=1;c<=N;c++){
            //目標値の対応ビットを取り出す
            auto colBit=(col.targets[c]>>pos)&1;
            auto rowBit=(row.targets[r]>>pos)&1;

            if (colBit^col.opcat[c]) matrix[r][c]|=(colBit<<pos);

            if (rowBit^row.opcat[r]) matrix[r][c]|=(rowBit<<pos);

            if (rowBit==colBit) matrix[r][c]|=(rowBit<<pos);
        }
    }
}

void SpecialInference(info_t& one,info_t& another,bool isRow,int pos){
    ull mask=(ull)1<<(ull)pos;
    for(int r=1;r<=N;r++){
        //今の桁を何にするかを表す
        auto bitTarget=(one.targets[r]>>pos)&one.opcat[r];
        if (!bitTarget||one.zeroCount[r]<N) continue;
        
        int c=1;
        while(c<=N){
            if (another.opcat[c]==0&&(another.targets[c]&mask)==0&&another.zeroCount[c]>1) break;
            c++;
        }
        if (c>N) continue;
        if (isRow)
            matrix[r][c]|=mask;
        else 
            matrix[c][r]|=mask;
        another.zeroCount[c]--;
        one.zeroCount[r]--;
    }
}

int main(){
    scanf("%d",&N);

    for(int i=1;i<=N;i++) scanf("%d",row.opcat+i);
    for(int i=1;i<=N;i++) scanf("%d",col.opcat+i);
    for(int i=1;i<=N;i++) scanf("%llu",row.targets+i);
    for(int i=1;i<=N;i++) scanf("%llu",col.targets+i);

    for(int bit=0;bit<64;bit++){
        ull mask=(ull)1<<(ull)bit;
        simpleInference(bit);

        memset(row.zeroCount,0,sizeof(row.zeroCount));
        memset(col.zeroCount,0,sizeof(col.zeroCount));
        for(int r=1;r<=N;r++)
            for(int w=1;w<=N;w++)
                if ((mask&matrix[r][w])==0) row.zeroCount[r]++,col.zeroCount[w]++;

        SpecialInference(row,col,true,bit);
        SpecialInference(col,row,false,bit);
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