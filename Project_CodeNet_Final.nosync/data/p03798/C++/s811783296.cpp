#include<bits/stdc++.h>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (n); i++)
 
int main(){
    int N;
    string S;
    cin >> N >> S;
    //sheep = 1 wolf = 0;
    vector<bool> SW(N+1);
    int J[4][2] = {
        {1,1},
        {1,0},
        {0,1},
        {0,0},
    };
    int I = 0;
    while(I < 4){
        SW[0] = J[I][0];
        SW[1] = J[I][1];
        for(int i=1;i<N;i++){
            if(SW[i] && S[i] == 'o'){
                SW[i+1] = SW[i-1];
            }else if(SW[i] && S[i] == 'x'){
                SW[i+1] = !SW[i-1];
            }else if(!SW[i] && S[i] == 'o'){
                SW[i+1] = !SW[i-1];
            }else if(!SW[i] && S[i] == 'x'){
                SW[i+1] = SW[i-1];
            }
        }
        bool a = SW[0] && S[0] == 'o' && SW[1] == SW[N-1];
        bool b = SW[0] && S[0] == 'x' && SW[1] != SW[N-1];
        bool c = !SW[0] && S[0] == 'o' && SW[1] != SW[N-1];
        bool d = !SW[0] && S[0] == 'x' && SW[1] == SW[N-1];
        bool e = SW[0] == SW[N];
        if(e && (a || b || c || d)){
            rep(i,N) cout << (SW[i] ? "S" : "W");
            cout << endl;
            return 0;
        }
        I++;
    }
    cout << -1 << endl;
    return 0;
}