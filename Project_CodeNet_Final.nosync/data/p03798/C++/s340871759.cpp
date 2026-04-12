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

void printAnimal(int num,int N){

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
        // 最初に決めたものと推定したものが一致する？
        bool flag1 = false; // 末尾が一致
        bool flag2 = false; // 先頭が一致
        REP(k,N){
            
            int cand;
            //１つ前と今見ている所のXORをとる
            if(k == 0){ //円環の繋ぎ目
                cand = candidate[i][N-1]^candidate[i][0];
            }else{
                cand = candidate[i][k-1]^candidate[i][k];
            }
            //XORは答えが"x"の時の次の動物を示す
            //"o"の時はビット反転させる
            if(s[k] == 'o'){
                cand = not(cand);
            }
            
            if(k != 0 && k == N-2){
                flag1 = (cand == candidate[i][k+1]);
                continue;
            }
            
            if(k != 0 && k == N-1){
                
                flag2 = (cand == candidate[i][0]);
                
                //推定したものが一致するなら出力して終了
                if(flag1 && flag2){
                    printAnimal(i,N);
                    return 0;
                }
            }
            candidate[i][k+1] = cand;
        }
        // i = 0~3まで(4つの候補)で一致しなければ存在しない
        if(i == 3) cout << -1 << endl;
    }

    return 0;
}
