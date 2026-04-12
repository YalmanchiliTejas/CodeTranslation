#include <bits/stdc++.h>

using namespace std;

vector<long long int> SO(50),PATY(50);

long long int dfs(long long int level, long long int sou){
    if(level==0){
        return 1;
    }else if(sou==1){
        return 0;
    }else if(sou<=SO[level-1]+1){
        return dfs(level-1,sou-1);
    }else if(sou == SO[level-1]+2){
        return PATY[level-1]+1;
    }else if(sou<=2+2*SO[level-1]){
        return PATY[level-1]+1+dfs(level-1,sou-SO[level-1]-2);
    }else{
        return 2*PATY[level-1]+1;
    }
}

int main(){
    long long int N,X;
    cin >> N >> X;
    SO[0] = 1;
    PATY[0] = 1;

    for(int i=1;i<=50;i++){
        SO[i] = 2*SO[i-1] + 3;
        PATY[i] = 2*PATY[i-1] + 1;
    }

    cout << dfs(N,X) << endl;
}