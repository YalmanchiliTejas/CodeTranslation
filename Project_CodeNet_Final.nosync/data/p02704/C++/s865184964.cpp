#include <cstdio>

typedef unsigned long long int ull;

int N;

ull targetOfRow[505],targetOfCol[505];
ull opcatOfRow[505],opcatOfCol[505];
ull matrix[505][505];

int zeroCountOfRow[64][505],zeroCountOfCol[64][505];

void shiftOp(){
    for(int i=1;i<=N;i++) opcatOfRow[i]<<=1,opcatOfCol[i]<<=1;
}

int main(){

    scanf("%d",&N);

    for(int i=1;i<=N;i++) scanf("%llu",opcatOfRow+i);
    for(int i=1;i<=N;i++) scanf("%llu",opcatOfCol+i);
    for(int i=1;i<=N;i++) scanf("%llu",targetOfRow+i);
    for(int i=1;i<=N;i++) scanf("%llu",targetOfCol+i);

    if (N==1){
        if (targetOfCol[1]==targetOfRow[1]){
            printf("%llu\n",targetOfRow[1]);
            return 0;
        }else{
            puts("-1");
            return 0;
        }
    }

    for(int bit=0;bit<64;bit++,shiftOp()){
        ull mask=(ull)1<<(ull)bit;
        //todo
        
        for(int r=1;r<=N;r++){
            for(int c=1;c<=N;c++){
                //目標値の対応ビットを取り出す
                auto colBit=targetOfCol[c]&mask;
                auto rowBit=targetOfRow[r]&mask;
                if ((colBit^opcatOfCol[c])
                    &&(rowBit^opcatOfRow[r])
                    &&(opcatOfRow[r]^opcatOfCol[c])
                    ) goto impossible;

                if (opcatOfCol[c]==opcatOfRow[r]){
                    if (opcatOfRow[r]==0) 
                        matrix[r][c]|=(colBit|rowBit);
                    else 
                        matrix[r][c]|=(colBit&rowBit);
                }

                if (colBit^opcatOfCol[c]) matrix[r][c]|=colBit;

                if (rowBit^opcatOfRow[r]) matrix[r][c]|=rowBit;
            }
        }

        // puts("basic");

        for(int r=1;r<=N;r++)
            for(int w=1;w<=N;w++)
                if ((mask&matrix[r][w])==0) zeroCountOfRow[bit][r]++,zeroCountOfCol[bit][w]++;

        for(int r=1;r<=N;r++){
            //今の桁を何にするかを表す
            auto bitTarget=targetOfRow[r]&opcatOfRow[r];
            if (!bitTarget||zeroCountOfRow[bit][r]<N) continue;

            // printf("r=%d\n",r);
            
            int c=1;
            while(c<=N){ 
                // printf("opcatOfCol[c]=%llu target=%llu",opcatOfCol[c],targetOfCol[c]);
                if (opcatOfCol[c]==0&&(targetOfCol[c]&mask)==0&&zeroCountOfCol[bit][c]>1) break;
                c++;
            }
            if (c>N) goto impossible;
            matrix[r][c]|=mask;
            zeroCountOfCol[bit][c]--;
            zeroCountOfRow[bit][r]--;
        }

        // puts("row");

        for(int c=1;c<=N;c++){
            //今の桁を何にするかを表す
            auto bitTarget=targetOfCol[c]&opcatOfCol[c];
            if (!bitTarget||zeroCountOfCol[bit][c]<N) continue;
            int r=1;
            while(r<=N) { 
                if (opcatOfRow[r]==0&&(targetOfRow[r]&mask)==0&&zeroCountOfRow[bit][r]>1) break;
                r++;
            }
            if (r>N) goto impossible;
            matrix[r][c]|=mask;
            zeroCountOfCol[bit][c]--;
            zeroCountOfRow[bit][r]--;
        }

        // puts("colums");
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++)
            printf("%llu ",matrix[i][j]);
            putchar('\n');
    }


    return 0;

impossible:
    puts("-1");
    return 0;
}