#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    //input
    long long N, M;
    cin >> N >> M;
    long long a[M], b[M];
    long long i, j;
    for(j = 0; j < M; j++){
        cin >> a[j] >> b[j];
    }

    //calc
    long long s[N];
    for(i = 0; i < N; i++){
        s[i] = i+1;
    }
    long long counta = 0;
    bool countif;
    do{
        countif = 1;
        for(i = 1; i < N; i++){
            for(j = 0; j < M; j++){
                if((s[i-1]==a[j] && s[i]==b[j]) || (s[i-1]==b[j] && s[i]==a[j])){
                    break;
                }
            }
            if(j==M){
                countif = 0;
            }
        }
        if(countif){
            counta++;
        }
    }while(next_permutation(s+1, s+N));

    //output
    cout << counta << endl;
    system("pause");
    return 0;
}