#include<iostream>

using namespace std;
//D. Menagerie

//円環状に羊か狼が並んでいる
//羊は正直で狼が嘘つき
//各動物に対して「両隣は同じ動物？」と質問
//各動物は"o"か"x"で答える

//動物の数 N と答えの文字列 s が与えられる
//あり得る組み合わせを羊ならS、狼ならWで出力
//組み合わせができない場合は-1を出力

#define FOR(i,a,b) for(long long i =(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define debug(x) cerr << #x << " = " << x << endl;
#define maxN 100000

int candidate[4][maxN];

void printAnimanl(int num,int N){

    REP(i,N){
        if(candidate[num][i] == 0){
            cout << "W";
        }else{
            cout << "S";
        }
    }
    cout << endl;
    return;
}

int main(void){

    
    int N;
    string s;

    cin >> N;
    cin >> s;
    
    fill((int*)candidate,(int*)(candidate+4),-1);
    
    // S = 1, W = 0で円環の繋ぎ目のあり得る組み合わせ(4つ)
    candidate[0][0]   = 0; candidate[0][N-1] = 0; // W W
    candidate[1][0]   = 0; candidate[1][N-1] = 1; // W S
    candidate[2][0]   = 1; candidate[2][N-1] = 0; // S W
    candidate[3][0]   = 1; candidate[3][N-1] = 1; // S S

    
    REP(i,4){
        bool flag1 = false;
        bool flag2 = false;
        REP(k,N){
            
            int cand;
            if(k == 0){
                cand = candidate[i][N-1]^candidate[i][0];
            }else{
                cand = candidate[i][k-1]^candidate[i][k];
            }
            
            if(s[k] == 'o'){
                cand = not(cand);
            }
            //debug(cand)
            if(k != 0 && k == N-2){
                flag1 = (cand == candidate[i][k+1]);
                continue;
            }
            if(k != 0 && k == N-1){
                flag2 = (cand == candidate[i][0]);
                if(flag1 && flag2){
                    printAnimanl(i,N);
                    return 0;
                }
            }
            candidate[i][k+1] = cand;
        }
        if(i == 3) cout << -1 << endl;
    }

    return 0;
}
