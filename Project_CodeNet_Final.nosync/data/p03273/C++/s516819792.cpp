#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int H, W, i, j, k, l, judge, count1=0, count2=0, retu[100], gyou[100], judge2;
    string a[100];

    cin >> H >> W;

    for(i=0; i<H; i++){
        cin >> a[i];
    }

    // 行
    for(i=0; i<H; i++){
        judge = 1;

        for(j=0; j<W; j++){
            if(a[i][j] == '#'){
                judge = 0;
            }
        }

        if(judge == 1){
            gyou[count1] = i;
            count1++;
        }
    }

    // 列
    for(i=0; i<W; i++){
        judge = 1;

        for(j=0; j<H; j++){
            if(a[j][i] == '#'){
                judge = 0;
            }
        }

        if(judge == 1){
            retu[count2] = i;
            count2++;
        }
    }

    for(i=0; i<H; i++){
        judge2 = 0;
        for(j=0; j<W; j++){
            judge = 1;
            
            for(k=0; k<=count1-1; k++){
                if(i == gyou[k]){
                    judge = 0;
                }
            }
            
            for(l=0; l<=count2-1; l++){
                if(j == retu[l]){
                    judge = 0;
                }
            }

            if(judge == 1){
                cout << a[i][j];

                judge2 = 1;
            }
        }

        if(judge2 == 1){
            cout << endl;
        }
    }

    return 0;
}  